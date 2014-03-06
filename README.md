# JPsi
CMSSW user code of Jan Veverka with packages originally intended for the J/psi
analysis of the first LHC data in 2010.

The JPsi/MuMu package contains
code for the PHOSPHOR fit - photon energy scale and resolution calibration
using Z -> mu mu gamma events.

There is also lot of old unused code and scripts around.

## History
These CMSSW packages were imported from the retired CVS
repository [1] on 5 March 2014.  Originally, they used to live at [2]
and were archived at [3].

They were imported using the HEAD version of cvs2git [4] using these commands:

    MY_GITHUB_USER=`git config --get user.github`
    MY_REMOTE=git@github.com:$MY_GITHUB_USER/JPsi.git
    /tmp/veverka/git/cvs2svn/cvs2git --options=my-cvs2git.options
    git init JPsi
    cd JPsi
    git remote add origin $MY_REMOTE
    cat ../git-blob.dat ../git-dump.dat | git fast-import

See also [5].  The file with the cvs2git options is stored at [6].

- [1] /afs/cern.ch/project/cvs/reps/CMSSW/UserCode/JanVeverka/JPsi
- [2] http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/UserCode/JanVeverka/JPsi
- [3] http://cvs.web.cern.ch/cvs/cgi-bin/viewcvs.cgi/UserCode/JanVeverka/JPsi
- [4] https://github.com/mhagger/cvs2svn/commit/b0ae0c98b0d5bf4b42425799814a9712d66c0073
- [5] http://cms-sw.github.io/cmssw/usercode-faq.html#how_do_i_migrate_to_github
- [6] https://github.com/janveverka/JPsi/blob/master/my-cvs2git.options
