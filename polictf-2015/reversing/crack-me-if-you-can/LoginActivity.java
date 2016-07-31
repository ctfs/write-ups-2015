package it.polictf2015;

import android.app.Activity;
import android.app.LoaderManager.LoaderCallbacks;
import android.content.Context;
import android.content.Loader;
import android.database.Cursor;
import android.os.Bundle;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends Activity implements LoaderCallbacks {
    private EditText f3685a;
    private View f3686b;

    private void m5319a() {
        View view = null;
        this.f3685a.setError(null);
        String obj = this.f3685a.getText().toString();
        Object obj2 = null;
        if (TextUtils.isEmpty(obj)) {
            this.f3685a.setError(getString(R.string.è));
            view = this.f3685a;
            obj2 = 1;
        }
        if (!(TextUtils.isEmpty(obj) || m5325a(obj))) {
            this.f3685a.setError(getString(R.string.à));
            view = this.f3685a;
            obj2 = 1;
        }
        if (obj2 != null) {
            view.requestFocus();
        }
    }

    private boolean m5321a(Context context, double d) {
        if (d != 3.41d) {
            double d2 = 1.0d + 3.41d;
        }
        return ((TelephonyManager) context.getSystemService("phone")).getSubscriberId().equalsIgnoreCase("310260000000000");
    }

    private boolean m5322a(Context context, int i) {
        if (i != 2) {
            int i2 = i + 1;
        }
        return ((TelephonyManager) context.getSystemService("phone")).getNetworkOperatorName().equalsIgnoreCase("android");
    }

    private boolean m5323a(Context context, String str) {
        str.replace("flagging", "flag");
        return ((TelephonyManager) context.getSystemService("phone")).getLine1Number().startsWith("1555521");
    }

    private boolean m5324a(Context context, boolean z) {
        String deviceId = ((TelephonyManager) context.getSystemService("phone")).getDeviceId();
        return deviceId.equalsIgnoreCase("000000000000000") || deviceId.equalsIgnoreCase("012345678912345") || deviceId.equalsIgnoreCase("e21833235b6eef10");
    }

    private boolean m5325a(String str) {
        if (!str.equals(C0673c.m5336a(C0672b.m5327a(C0672b.m5328b(C0672b.m5329c(C0672b.m5330d(C0672b.m5333g(C0672b.m5334h(C0672b.m5331e(C0672b.m5332f(C0672b.m5335i(C0673c.m5338c(C0673c.m5337b(C0673c.m5339d(getString(R.string.àè)))))))))))))))) {
            return false;
        }
        Toast.makeText(getApplicationContext(), getString(R.string.ìò), 1).show();
        return true;
    }

    public void m5326a(Loader loader, Cursor cursor) {
    }

    protected void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        setContentView(R.layout.activity_login);
        if (m5322a(getApplicationContext(), 2) || m5323a(getApplicationContext(), "flagging{It_cannot_be_easier_than_this}") || m5324a(getApplicationContext(), false) || m5321a(getApplicationContext(), 2.78d)) {
            Toast.makeText(getApplicationContext(), getString(R.string.ù), 1).show();
        } else {
            Toast.makeText(getApplicationContext(), getString(R.string.àù), 1).show();
        }
        this.f3685a = (EditText) findViewById(R.id.flag);
        ((Button) findViewById(R.id.sign_in_button)).setOnClickListener(new C0671a(this));
        this.f3686b = findViewById(R.id.login_form);
    }

    public Loader onCreateLoader(int i, Bundle bundle) {
        return null;
    }

    public /* synthetic */ void onLoadFinished(Loader loader, Object obj) {
        m5326a(loader, (Cursor) obj);
    }

    public void onLoaderReset(Loader loader) {
    }
}
