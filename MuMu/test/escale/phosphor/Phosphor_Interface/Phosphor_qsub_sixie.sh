#!/bin/sh

QSUBDIR=/home/cmorgoth/phosphor/CMSSW_4_2_8_patch7/src/JPsi/MuMu/test/escale/phosphor/Phosphor_Interface/QsubScripts_sixie_LowR9_ExpFit_MoreBins


NEWDIR=`date | gawk '{ print $1 $2 $3"_" $6 }'`
RESULTS=NV_HighInf_2012ABCD_HggRegression_newMuCorr_LowR9
LOGS=NV_HighInf_2012ABCD_HggRegression_newMuCorr_LowR9_Logs
TreeVer="sixie"

RESDIR=Dir_Results

if [ -d $RESDIR/$NEWDIR ]; then
	echo "DIR $RESDIR/$NEWDIR exists."
	if [ -d $RESDIR/$NEWDIR/$RESULTS ]; then
		echo "DIR $RESDIR/$NEWDIR/$RESULTS exists."
	else
		mkdir $RESDIR/$NEWDIR/$RESULTS
		echo "Creating DIR: $RESDIR/$NEWDIR/$RESULTS."
	fi

	if [ -d $RESDIR/$NEWDIR/$LOGS ]; then
		echo "DIR $RESDIR/$NEWDIR/$LOGS exists."
	else
		mkdir $RESDIR/$NEWDIR/$LOGS
		echo "Creating DIR: $RESDIR/$NEWDIR/$LOGS."
	fi

		
else
	mkdir $RESDIR/$NEWDIR
	echo "Creating DIR: $RESDIR/$NEWDIR."
	mkdir $RESDIR/$NEWDIR/$RESULTS
	echo "Creating DIR: $RESDIR/$NEWDIR/$RESULTS."
	mkdir $RESDIR/$NEWDIR/$LOGS
	echo "Creating DIR: $RESDIR/$NEWDIR/$LOGS."
fi


for qfiles in $QSUBDIR/*.sge; do
    pwd; echo $qfiles; SGEFILE=$qfiles; echo $SGEFILE    
    if [ -a $SGEFILE ] 
	then 
	echo "QSUB"

	qsub -j y -o $RESDIR/$NEWDIR/$LOGS -q all.q@compute-1-5.local,all.q@compute-0-1.local,all.q@compute-0-2.local,all.q@compute-0-6.local,all.q@compute-1-0.local,all.q@compute-1-4.local,all.q@compute-1-7.local,all.q@compute-1-3.local,all.q@compute-1-2.local,all.q@compute-1-6.local $SGEFILE  -- $RESDIR/$NEWDIR/$RESULTS $TreeVer;
	#qsub -j y -o $NEWDIR/$LOGS -q all.q@compute-1-5.local,all.q@compute-1-3.local,all.q@compute-0-1.local,all.q@compute-0-0.local $SGEFILE  -- $NEWDIR/$RESULTS $TreeVer;
#qsub -j y -o $NEWDIR/$LOGS -q all.q@compute-1-2.local $SGEFILE  -- $NEWDIR/$RESULTS $TreeVer;
	#sdfdf

    else

	echo "FILE $SGEFILE DOES NOT EXIT, DOING NOTHING"
    fi
    #cd $INITIALTOPDIR;
done



