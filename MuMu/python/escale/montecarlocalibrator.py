'''
Given a selection and photon scale and resolution,
fetch a RooDataSet of mmgMass MC data smeared such that the photon detector
responce Ereco/Etrue has the same shape as the nominal MC but has the given
scale and resolution.
'''
### TODO: turn this into a class that can produce smeared data through a simple
### interface.

import ROOT
import JPsi.MuMu.common.roofit as roo
from JPsi.MuMu.common.parametrizedkeyspdf import ParametrizedKeysPdf

##------------------------------------------------------------------------------
class MonteCarloCalibrator:
    def __init__(self, data):
        self.w = ROOT.RooWorkspace('mccworkspace',
                                   'MonteCarloCalibrator Workspace')
        self.datarow = ROOT.RooArgSet()
        for x in 'mmMass mmgMass phoERes'.split():
            setattr(self, x, data.get()[x])
            self.datarow.add(data.get()[x])
            # self.w.Import(getattr(self, x))
        self.data = data.reduce(self.datarow)
        self.data.SetName('data')
        self.w.Import(data)

        ## Define reference (0) and target scale (s) and resolution (r)
        self.s0 = self.w.factory('s0[0, -50, 50]')
        self.r0 = self.w.factory('r0[1, 0.01, 50]')
        self.s = self.w.factory('s[0, -50, 50]')
        self.r = self.w.factory('r[1, 0.01, 50]')
        for x in 's0 r0 s r'.split():
            getattr(self, x).setUnit('%')

        ## Define a set of the reference parameters, store it in the workspace.
        self.sr = ROOT.RooArgSet(self.s, self.r)
        self.sr0 = ROOT.RooArgSet(self.s0, self.r0)
        self.w.defineSet('fit', self.sr)
        self.w.defineSet('ref', self.sr0)
        self.w.saveSnapshot('sr_init', self.sr, True)
        self.w.saveSnapshot('sr0_init', self.sr0, True)

        self._get_mctruth_scale_and_resolution()
        self._define_smearing_functions()
    ## end of __init__

    def _get_mctruth_scale_and_resolution(self):
        ## Enlarge the range of the observable to get vanishing tails for
        ## the photon energy scale resolution        
        savrange = (self.phoERes.getMin(), self.phoERes.getMax())
        self.phoERes.setRange(savrange[0] - 10, savrange[1] + 10)

        ## Build the model for the photon energy resolution.
        self.phoEResPdf = ParametrizedKeysPdf('phoEResPdf', 'phoEResPdf',
                                              self.phoERes, self.s, self.r,
                                              self.data,
                                              ROOT.RooKeysPdf.NoMirror, 1.5)
        self.phoERes.setRange(*savrange)
        
        ## Extract the MC truth scale and resolution from MC
        self.phoEResPdf.fitTo(self.data, roo.PrintLevel(-1),
                              roo.SumW2Error(False))

        ## Store the MC truth scale and resolution
        self.s0.setVal(self.s.getVal())
        self.r0.setVal(self.r.getVal())
        self.w.saveSnapshot('sr_mctruth', self.sr)
        self.w.saveSnapshot('sr0_mctruth', self.sr0)
        self.s0.setConstant(True)
        self.r0.setConstant(True)
    ## end of _get_mctruth_scale_and_resolution

    def _define_smearing_functions(self):
        ## Define the smearing formulas for photon energy and mmg invariant mass
        # self.phoEResSmear = w.factory('phoEResSmear[-100,200]')
        self.phoEResSmear = self.w.factory('''expr::phoEResSmear(
            "s + r * (phoERes - s0) / r0",
            {phoERes, s, r, s0, r0}
            )''')

        # self.mmgMassSmear = w.factory('mmgMassSmear[0, 200]')
        self.mmgMassSmear = self.w.factory('''expr::mmgMassSmear(
            "sqrt({m2} + (1 + 0.01 * {f}) / (1 + 0.01 * {f0}) * ({M2} - {m2}))",
            {{{m}, {M}, {f}, {f0}}}
            )'''.format(m='mmMass', m2='mmMass*mmMass', M='mmgMass',
                        M2='mmgMass*mmgMass', f='phoEResSmear', f0='phoERes')
            )
    ## end of _define_smearing_functions

    def _reduce_and_rename(self, oldname, newname):
        ## Remove the ranges from the oldvar.
        oldvar = self.data.get()[oldname]
        oldvar.removeMin()
        oldvar.removeMax()
        ## Drop everything except the oldvar.
        newdata = self.data.reduce(ROOT.RooArgSet(oldvar))
        ## Define the renaming identity newvar = oldvar
        newfunc = ROOT.RooFormulaVar(newname, newname, oldname,
                                     ROOT.RooArgList(oldvar))
        ## Add a column with the identical values but with the new name
        newvar = newdata.addColumn(newfunc)
        ## New data now contains two columns of identical values, one labeled
        ## with the old name and the other with the new name. Keep only the one
        ## with the new name.
        return newdata.reduce(ROOT.RooArgSet(newvar))        
    ## end of _reduce_and_rename

    def get_smeared_data(self, starget, rtarget):
        self.s.setVal(starget)
        self.r.setVal(rtarget)
        ## Make sure that the reference scale and resolution
        ## are equal to the MC truth.
        self.w.loadSnapshot('sr0_mctruth')
        ## Calculate the smeared photon energy resolution and mmg mass.
        self.data.addColumn(self.phoEResSmear)
        self.data.addColumn(self.mmgMassSmear)
        ## Build a new dataset with the smeared data
        self.sdata = self.data.reduce(ROOT.RooArgSet(self.mmMass))
        self.sdata.merge(self._reduce_and_rename('phoEResSmear', 'phoERes'))
        self.sdata.merge(self._reduce_and_rename('mmgMassSmear', 'mmgMass'))
        ## Drop the smearing variables from the nominal data
        self.data = self.data.reduce(ROOT.RooArgSet(self.mmgMass,
                                                    self.mmMass,
                                                    self.phoERes))
        ## Set the name and title of the smeared data.
        self.sdata.SetName(self.data.GetName() + '_smeared')
        self.sdata.SetTitle(self.data.GetTitle() + ' smeared')
        print '+++ Exiting MonteCarloCalibrator.get_smeared_data().'
        ## Return the smeared data
        return self.sdata
    ## end of get_smeared_data
## end of MonteCarloCalibrator
    
##------------------------------------------------------------------------------
def main():
    pass
## end of main

##------------------------------------------------------------------------------
## Footer stuff
if __name__ == "__main__":
    main()
    import user