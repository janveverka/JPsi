'''
Plot mean and width of s vs pt for Lyon and Caltech MC and MC truth
    Usage: python -i frp_caltech_vs_lyon.py
'''

import JPsi.MuMu.common.canvases as canvases
from JPsi.MuMu.escale.fitResultPlotter import FitResultPlotter
from JPsi.MuMu.common.binedges import BinEdges
from JPsi.MuMu.common.basicRoot import *
from JPsi.MuMu.common.roofit import *
from JPsi.MuMu.escale.lyondata import data_2011_09_23_confID155805 as lyon
from JPsi.MuMu.scaleFitter import subdet_r9_categories

gStyle.SetPadTopMargin(0.1)
canvases.wwidth = 400
canvases.wheight = 400
canvases.yperiod = 10

filename = '/raid2/veverka/esFitResults/mc_sreco_strue_Baseline_V1.root'
filename = '/Users/veverka/Work/Talks/11-11-04/mc_sreco_strue_Baseline_V1.root'

plotters = []

## Configuration for plots vs Pt
binedges = list(BinEdges([10, 12, 15, 20, 25, 30, 100]))
bincenters = [0.5*(lo + hi)
              for lo, hi in BinEdges([10, 12, 15, 20, 25, 30, 50])]
binhalfwidths = [0.5*(hi - lo)
                 for lo, hi in BinEdges([10, 12, 15, 20, 25, 30, 50])]
n = len(binedges)
# binhalfwidths = [0] * n

def var_vs_pt(name):
    """Returns functions that take a workspaces ws and return
    x, y, ex, ey where y and ey correspond to workspace
    variable of a given name and x and ex are pt bins."""
    return (
        lambda ws, i = iter(bincenters): i.next(),    # x
        lambda ws: ws.var(name).getVal(),             # y
        lambda ws, i = iter(binhalfwidths): i.next(), # ex
        lambda ws: ws.var(name).getError(),           # ey
    )

categories = 'EB_lowR9 EB_highR9 EE_lowR9 EE_highR9'.split()
lyonmc = lyon['mc']

class Config():
    """Holds fitResultPlotter configuration data."""
    def __init__(self, **kwargs):
        for name, value in kwargs.items():
            setattr(self, name, value)
## end of Config

cfgs = [
    ###########################################################################
    ## EB, R9 < 0.94, mmMass < 80 GeV, mmgMass in [87.2, 95.2]
    Config(
        ## Used to pick the right Lyon data and in canvas name
        name = 'EB_lowR9',
        ## Used in canvas title
        title = 'Barrel, R_{9} < 0.94, Baseline Selection, POWHEG S4',
        filenames = [filename] * n,
        wsnames = ('ws1',) * n,
        sreco_snapshots = ['sFit_sreco_mc_cbShape_mmMass80_EB_lowR9_PhoEt%d-%d'
                           % (lo, hi) for lo, hi in binedges],
        ## MC truth scale
        strue_snapshots = ['sFit_strue_mc_bifurGauss_mmMass80_EB_lowR9_'
                           'PhoEt%d-%d' % (lo, hi) for lo, hi in binedges],
    ),
    ###########################################################################
    ## EB, R9 > 0.94, mmMass < 80 GeV, mmgMass in [87.2, 95.2]
    Config(
        ## Used to pick the right Lyon data and in canvas name
        name = 'EB_highR9',
        ## Used in canvas title
        title = 'Barrel, R_{9} > 0.94, Baseline Selection, POWHEG S4',
        filenames = [filename] * n,
        wsnames = ('ws1',) * n,
        sreco_snapshots = ['sFit_sreco_mc_cbShape_mmMass80_EB_highR9_PhoEt%d-%d'
                           % (lo, hi) for lo, hi in binedges],
        ## MC truth scale
        strue_snapshots = ['sFit_strue_mc_bifurGauss_mmMass80_EB_highR9_'
                           'PhoEt%d-%d' % (lo, hi) for lo, hi in binedges],
    ),
    ###########################################################################
    ## EE, R9 < 0.95, mmMass < 80 GeV, mmgMass in [87.2, 95.2]
    Config(
        ## Used to pick the right Lyon data and in canvas name
        name = 'EE_lowR9',
        ## Used in canvas title
        title = 'Endcaps, R_{9} < 0.95, Baseline Selection, POWHEG S4',
        filenames = [filename] * n,
        wsnames = ('ws1',) * n,
        sreco_snapshots = ['sFit_sreco_mc_cbShape_mmMass80_EE_lowR9_PhoEt%d-%d'
                           % (lo, hi) for lo, hi in binedges],
        ## MC truth scale
        strue_snapshots = ['sFit_strue_mc_bifurGauss_mmMass80_EE_lowR9_'
                           'PhoEt%d-%d' % (lo, hi) for lo, hi in binedges],
    ),
    ###########################################################################
    ## EE, R9 > 0.95, mmMass < 80 GeV, mmgMass in [87.2, 95.2]
    Config(
        ## Used to pick the right Lyon data and in canvas name
        name = 'EE_highR9',
        ## Used in canvas title
        title = 'Endcaps, R_{9} > 0.95, Baseline Selection, POWHEG S4',
        filenames = [filename] * n,
        wsnames = ('ws1',) * n,
        sreco_snapshots = ['sFit_sreco_mc_cbShape_mmMass80_EE_highR9_PhoEt%d-%d'
                           % (lo, hi) for lo, hi in binedges],
        ## MC truth scale
        strue_snapshots = ['sFit_strue_mc_bifurGauss_mmMass80_EE_highR9_'
                           'PhoEt%d-%d' % (lo, hi) for lo, hi in binedges],
    ),
]


for cfg in cfgs:
    #------------------------------------------------------------------------------
    ## Scale Comparison
    ## Lyon
    frp = FitResultPlotter(
        sources = zip(cfg.filenames, cfg.wsnames, cfg.sreco_snapshots),
        getters = (
            lambda ws, i = iter(bincenters): i.next(),    # x
            lambda ws, i = iter(lyonmc[cfg.name]['sreco']): i.next(), # y
            lambda ws, i = iter(binhalfwidths): i.next(), # ex
            lambda ws, i = iter(lyonmc[cfg.name]['esreco']): i.next(), # ey
            ),
        xtitle = 'E_{T}^{#gamma} (GeV)',
        ytitle = 's_{reco} = E^{#gamma}_{reco}/E^{kin}_{reco} - 1 (%)',
        title = 'Lyon',
        )
    frp.getdata()
    frp.makegraph()

    ## Caltech
    frp.getters = var_vs_pt('#Deltas')
    frp.title = 'Caltech'
    frp.getdata()
    frp.makegraph()

    ## True
    frp.sources = zip(cfg.filenames, cfg.wsnames, cfg.strue_snapshots)
    frp.getters = var_vs_pt('#Deltas')
    frp.title = 'MC Truth'
    frp.getdata()
    frp.makegraph()

    ## Compare Caltech, Lyon and MC truth scale
    canvases.next('s_' + cfg.name).SetGrid()
    frp.plotall(title = cfg.title,
                styles = [20, 25, 22],
                colors = [kBlue, kRed, kBlack])

    plotters.append(frp)

    #------------------------------------------------------------------------------
    ## S width Comparison
    ## Lyon
    frp = FitResultPlotter(
        sources = zip(cfg.filenames, cfg.wsnames, cfg.sreco_snapshots),
        getters = (
            lambda ws, i = iter(bincenters): i.next(),    # x
            lambda ws, i = iter(lyonmc[cfg.name]['sigma']): i.next(),    # y
            lambda ws, i = iter(binhalfwidths): i.next(), # ex
            lambda ws, i = iter(lyonmc[cfg.name]['esigma']): i.next(),   # ey
            ),
        xtitle = 'E_{T}^{#gamma} (GeV)',
        ytitle = '#sigma(s_{reco}) (%)',
        title = 'Lyon',
        )
    frp.getdata()
    frp.makegraph()

    ## Caltech
    frp.getters = var_vs_pt('#sigma')
    frp.title = 'Caltech'
    frp.getdata()
    frp.makegraph()

    ## Compare Caltech and Lyon s width
    canvases.next('sigma_' + cfg.name).SetGrid()
    frp.plotall(title = cfg.title,
                styles = [20, 25])

    plotters.append(frp)
## end of loop over cfgs



################################################################################
## Plot the p-values of the MC true fits
filenames = [filename] * n
workspaces = ['ws1'] * n
snapshot = 'chi2_strue_mc_bifurGauss_mmMass80_%s_PhoEt%d-%d_iter0'
cats = list(subdet_r9_categories)

frp = FitResultPlotter(
    sources = zip([filename] * n,
                  ['ws1'] * n,
                  [snapshot % ('EB_highR9', lo, hi) for lo, hi in binedges]),
    getters =  var_vs_pt('chi2Prob'),
    xtitle = 'E_{T}^{#gamma} (GeV)',
    ytitle = 'p-value',
    title = 'Barrel, R_{9}^{#gamma} < 0.94',
    )

for icat in cats:
    frp.sources = zip(filenames, workspaces,
                      [snapshot % (icat.name, lo, hi) for lo, hi in binedges])
    frp.getters = var_vs_pt('chi2Prob')
    frp.title = ', '.join(icat.labels)
    frp.getdata()
    frp.makegraph()

canvases.next('strue_pvalues_vs_phoEt')
frp.plotall(title = 'MC Truth Fits')
plotters.append(frp)

## Make the distribution of the p-values
hist = frp.histogramall(
    name = 'h_strue_pvalues',
    title = 's_{true} = E^{#gamma}_{reco}/E^{#gamma}_{gen};p-value;Fits',
    nbins = 5, xlow = 0, xhigh = 1
    )
canvases.next('strue_pvalues_distro')
hist.Draw('e0')
plotters.append(hist)

################################################################################
## Plot the p-values of the reco s-Fits fits
filenames = [filename] * n
workspaces = ['ws1'] * n
snapshot = 'chi2_sreco_mc_cbShape_mmMass80_%s_PhoEt%d-%d_iter0'

frp = FitResultPlotter(
    sources = zip([filename] * n,
                  ['ws1'] * n,
                  [snapshot % ('EB_highR9', lo, hi) for lo, hi in binedges]),
    getters =  var_vs_pt('chi2Prob'),
    xtitle = 'E_{T}^{#gamma} (GeV)',
    ytitle = 'p-value',
    title = 'Barrel, R_{9}^{#gamma} > 0.94',
    )

for icat in cats:
    frp.sources = zip(filenames, workspaces,
                      [snapshot % (icat.name, lo, hi) for lo, hi in binedges])
    frp.getters = var_vs_pt('chi2Prob')
    frp.title = ', '.join(icat.labels)
    frp.getdata()
    frp.makegraph()

canvases.next('sreco_pvalues_vs_phoEt').SetLogy()
frp.plotall(logy = True, title = 's_{reco} Fits')

## Make the distribution of the p-values
hist = frp.histogramall(
    name = 'h_sreco_pvalues',
    title = 's_{reco} = E^{#gamma}_{reco}/E^{#gamma}_{kin};p-value;Fits',
    nbins = 5, xlow = 0, xhigh = 1
    )
c1 = canvases.next('sreco_pvalues_distro')
hist.Draw('e0')
plotters.append(hist)

c1.Update()

if __name__ == '__main__':
    import user
