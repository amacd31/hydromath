import sys
import os
import yaml
import jinja2
import glob
from conda_build.config import Config
from conda_build.metadata import MetaData
from distutils.version import LooseVersion

config = Config()
recipe_metadata = MetaData(os.path.join(sys.argv[1]))
binary_package_glob = os.path.join(config.bldpkgs_dir, '{0}*.tar.bz2'.format(recipe_metadata.name()))
binary_package = sorted(glob.glob(binary_package_glob), key=LooseVersion, reverse = True)[0]

print(binary_package)
