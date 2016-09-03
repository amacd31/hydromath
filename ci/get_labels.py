import os
import versioneer

ci_dir = os.path.dirname(os.path.abspath(__file__))
version_info = versioneer.git_pieces_from_vcs('v', os.path.join(ci_dir, '..'), False)

labels = ['--label dev']
if version_info['distance'] == 0:
    labels.append('--label test')

print(' '.join(labels))
