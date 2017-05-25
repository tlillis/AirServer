set -x #echo commands
cd cross_build
tar cvzf airserver.tar.gz airserver lib config.xml
rm airserver
mkdir airserver
cp airserver.tar.gz install.sh README.md airserver
tar cvzf cross_build.tar.gz airserver
scp -r cross_build.tar.gz  lillis@recuv-ops.colorado.edu:../../fileshare/http
rm -r airserver
rm cross_build.tar.gz
rm airserver.tar.gz