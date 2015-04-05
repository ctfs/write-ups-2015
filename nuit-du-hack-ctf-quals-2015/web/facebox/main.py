#!/usr/bin/env python
# -*- coding: utf-8 -*-


def generate_random_filename(user_id,filename):
    dbuser = users.query.filter_by(id=user_id).first()

    if dbuser.privkey is not None:
        return md5(str(dbuser.privkey)+filename).hexdigest()
    else:
        privkey = str(randint(10000000,99999999))
        upd = users.query.filter_by(id=user_id).first()
        upd.privkey = privkey
        db.session.commit()
    return md5(str(privkey)+filename).hexdigest()