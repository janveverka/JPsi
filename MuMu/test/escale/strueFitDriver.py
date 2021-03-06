import os
import JPsi.MuMu.common.dataset as dataset
import JPsi.MuMu.common.energyScaleChains as esChains

from JPsi.MuMu.common.basicRoot import *
from JPsi.MuMu.common.roofit import *
from JPsi.MuMu.common.plotData import PlotData
from JPsi.MuMu.strueFitter import STrueFitter

## Get the data
_chains = esChains.getChains('v10')

## Cuts common to all plots
_commonCuts = [
#     'abs(mmgMass-91.2) < 4',
#     'abs(mmgMass-92.12) < 4.253'
    'mmMass < 80',
]

defaultFit  = STrueFitter(
    name = 'dummy',
    title = 'Barrel, R9 > 0.94, Powheg S4',
    source = _chains['z'],
    expression = '100 * (phoE/phoGenE - 1)',
    cuts = _commonCuts + [ 'phoIsEB',
                           'phoR9 < 0.94',
                           '30 < phoPt', 'phoPt < 9999',
                           'abs(mmgMass-92.12) < 4.253' ],
    labels = [ 'Barrel', 'R_{9}^{#gamma} > 0.94', 'Powheg S4' ],
    xRange = (-20, 30),
    nBins = 100
)


## ----------------------------------------------------------------------------
## Customize below
_fits = [
    ## Barrel, MC
    defaultFit.clone(
        name = 'strue_EB_lowR9_mc_pt10-12_mmMass85',
        title = 'Barrel, R9 < 0.94, Powheg S4, pt 10-12 GeV, m(mm) < 85 GeV',
        cuts = ['isFSR',
                'phoIsEB',
                'phoR9 < 0.94',
                '10 < phoPt', 'phoPt < 12',
                'abs(mmgMass-91.62) < 4.23',
                'mmMass < 85'],
        labels = ['Barrel',
                  'R_{9}^{#gamma} < 0.94',
                  'Powheg S4',
                  'E_{T}^{#gamma} #in [10, 12] GeV',
                  'm_{#mu^{+}#mu^{-}} < 85 GeV' ],
        source = _chains['z'],
        expression = '100 * (phoE/phoGenE - 1)',
        fitRange = (0, 10),
        xRange = (-10, 40),
        nBins = 50,
    ),
    defaultFit.clone(
        name = 'strue_EB_lowR9_mc_pt10-12_mmMass80',
        title = 'Barrel, R9 < 0.94, Powheg S4, pt 10-12 GeV, m(mm) < 80 GeV',
        cuts = ['isFSR',
                'phoIsEB',
                'phoR9 < 0.94',
                '10 < phoPt', 'phoPt < 12',
                'abs(mmgMass-90.99) < 3.86',
                'mmMass < 80'],
        labels = ['Barrel',
                  'R_{9}^{#gamma} < 0.94',
                  'Powheg S4',
                  'E_{T}^{#gamma} #in [10, 12] GeV',
                  'm_{#mu^{+}#mu^{-}} < 80 GeV' ],
        source = _chains['z'],
        expression = '100 * (phoE/phoGenE - 1)',
        fitRange = (0, 10),
        xRange = (-10, 40),
        nBins = 50,
    ),
    defaultFit.clone(
        name = 'strue_EB_lowR9_mc_pt10-12_mmMass75',
        title = 'Barrel, R9 < 0.94, Powheg S4, pt 10-12 GeV, m(mm) < 75 GeV',
        cuts = ['isFSR',
                'phoIsEB',
                'phoR9 < 0.94',
                '10 < phoPt', 'phoPt < 12',
                'abs(mmgMass-89.07) < 4.75',
                'mmMass < 75'],
        labels = ['Barrel',
                  'R_{9}^{#gamma} < 0.94',
                  'Powheg S4',
                  'E_{T}^{#gamma} #in [10, 12] GeV',
                  'm_{#mu^{+}#mu^{-}} < 75 GeV' ],
        source = _chains['z'],
        expression = '100 * (phoE/phoGenE - 1)',
        fitRange = (0, 10),
        xRange = (-10, 40),
        nBins = 50,
    ),
    defaultFit.clone(
        name = 'strue_EB_lowR9_mc_pt30-999_mmMass80',
        title = 'Barrel, R9 < 0.94, Powheg S4, pt > 30 GeV, m(mm) < 80 GeV',
        cuts = ['isFSR',
                'phoIsEB',
                'phoR9 < 0.94',
                '30 < phoPt', 'phoPt < 9999',
                'abs(mmgMass-92.10) < 4.23',
                'mmMass < 80'],
        labels = ['Barrel',
                  'R_{9}^{#gamma} < 0.94',
                  'Powheg S4',
                  'E_{T}^{#gamma} > 30 GeV',
                  'm_{#mu^{+}#mu^{-}} < 80 GeV' ],
        source = _chains['z'],
        expression = '100 * (phoE/phoGenE - 1)',
        fitRange = (0, 4.5),
        xRange = (-5, 20),
        nBins = 100,
    ),
#     defaultFit.clone(
#         name = 'strue_EB_lowR9_mc_default',
#         title = 'Barrel, R9 < 0.94, Powheg S4, default corrections',
#         source = _chains['z'],
#         expression = '100 * (phoE/phoGenE - 1)',
#         cuts = _commonCuts + ['phoIsEB', 'phoR9 < 0.94'],
#         labels = [ 'Barrel', 'R_{9}^{#gamma} < 0.94', 'Powheg S4',
#                    'Default Corr.' ],
#         fitRange = (-2, 9),
#         xRange = (-30, 50),
#     ),
#     defaultFit.clone(
#         name = 'strue_EB_lowR9_mc_default_closure',
#         title = 'Barrel, R9 < 0.94, Powheg S4, default corrections, closure test',
#         source = _chains['z'],
#         expression = '100 * (corrE/phoGenE - 1)',
#         cuts = _commonCuts + ['phoIsEB', 'phoR9 < 0.94'],
#         labels = [ 'Barrel', 'R_{9}^{#gamma} < 0.94', 'Powheg S4',
#                    'Default Corr.', 'Closure Test' ],
#         fitRange = (-2, 9),
#         xRange = (-30, 50),
#     ),
#     defaultFit.clone(
#         name = 'strue_EB_lowR9_mc_new',
#         title = 'Barrel, R9 < 0.94, Powheg S4, new corrections',
#         source = _chains['z'],
#         expression = '100 * (newCorrE/phoGenE - 1)',
#         cuts = _commonCuts + ['phoIsEB', 'phoR9 < 0.94'],
#         labels = [ 'Barrel', 'R_{9}^{#gamma} < 0.94', 'Powheg S4',
#                    'New Corr.' ],
#         fitRange = (-4, 7),
#         xRange = (-30, 50),
#     ),
#
#     ## Endcaps, MC
#     defaultFit.clone(
#         name = 'strue_EE_highR9_mc',
#         title = 'Endcaps, R9 > 0.95, Powheg S4',
#         source = _chains['z'],
#         expression = '100 * (1/kRatio - 1)',
#         cuts = _commonCuts + ['!phoIsEB', 'phoR9 > 0.95'],
#         labels = [ 'Endcaps', 'R_{9}^{#gamma} > 0.95', 'Powheg S4' ],
#         xRange = (-30, 50),
#         fitRange = (-15, 10),
#     ),
#     defaultFit.clone(
#         name = 'strue_EE_lowR9_mc_default',
#         title = 'Endcaps, R9 < 0.95, Powheg S4, default corrections',
#         source = _chains['z'],
#         expression = '100 * (1/kRatio - 1)',
#         cuts = _commonCuts + ['!phoIsEB', 'phoR9 < 0.95'],
#         labels = [ 'Endcaps', 'R_{9}^{#gamma} < 0.95', 'Powheg S4',
#                    'Default Corr.' ],
#         xRange = (-30, 50),
#         fitRange = (-15, 15),
#     ),
#     defaultFit.clone(
#         name = 'strue_EE_lowR9_mc_default_closure',
#         title = 'Endcaps, R9 < 0.95, Powheg S4, default corrections, closure test',
#         source = _chains['z'],
#         expression = '100 * (1/corrKRatio - 1)',
#         cuts = _commonCuts + ['!phoIsEB', 'phoR9 < 0.95'],
#         labels = [ 'Endcaps', 'R_{9}^{#gamma} < 0.95', 'Powheg S4',
#                    'Default Corr.', 'Closure Test' ],
#         xRange = (-30, 50),
#         fitRange = (-15, 15),
#     ),
#     defaultFit.clone(
#         name = 'strue_EE_lowR9_mc_new',
#         title = 'Endcaps, R9 < 0.95, Powheg S4, new corrections',
#         source = _chains['z'],
#         expression = '100 * (1/newCorrKRatio - 1)',
#         cuts = _commonCuts + ['!phoIsEB', 'phoR9 < 0.95'],
#         labels = [ 'Endcaps', 'R_{9}^{#gamma} < 0.95', 'Powheg S4',
#                    'New Corr.' ],
#         xRange = (-30, 50),
#         fitRange = (-20, 15),
#     ),

]



## Define the workspace
ws1 = RooWorkspace( 'ws1', 'mmg energy scale' )

## Define the quantity to be fitted
x = RooRealVar( 's', '100 * (phoE/phoGenE - 1)', -50, 50, '%' )
w = RooRealVar( 'w', 'pileup.weight', 0, 99 )

xw = RooArgSet(x, w)
ws1.Import(xw)

# model = ws1.factory("""CBShape::model( s,
#                                        #mu[0, -10, 10],
#                                        #sigma[2, 0.001, 10],
#                                        #alpha[1.5, -10, 0],
#                                        n[1.5, 0.1, 10] )""")

model = ws1.factory("""Gaussian::model( s,
                                        #mu[0, -20, 30],
                                        #sigma[2, 0.001, 50] )""")

## Define observables and parameters
observables = RooArgSet(x)
parameters = model.getParameters(observables)
ws1.defineSet("parameters", parameters)
ws1.saveSnapshot("initial", parameters, True)

## Loop over plots
getMu, getSigma = ws1.var('#mu').getVal, ws1.var('#sigma').getVal
for fitter in _fits:
    fitter.fit(ws1)

## <-- loop over plots

## Print a spreadsheet report
print '\nSpreadsheet report'
for plot in _fits:
    ws1.loadSnapshot( plot.name )
    print '%10f\t%10f\t%s' % ( ws1.var('#mu').getVal(),
                               ws1.var('#mu').getError(),
                               plot.title )
## <-- loop over plots


## Print a latex report
print "\nLatex report"
for plot in _fits:
    ws1.loadSnapshot( plot.name )
    print '  %50s | %6.2f $\pm$ %4.2f \\\\' % (
        plot.title,
        ws1.var('#mu').getVal(),
        ws1.var('#mu').getError()
    )
## <-- loop over plots


## Print an ASCII report
print '\nASCII report'
for plot in _fits:
    ws1.loadSnapshot( plot.name )
    print '%6.2f +/- %4.2f' % ( ws1.var('#mu').getVal(),
                                ws1.var('#mu').getError() ), plot.title
## <-- loop over plots


if __name__ == "__main__": import user
