// familyd.c �������е�������Ϣ

#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

// �������������20��
#define MAX_FAMILY_FAME         300000

// ÿ�����������100������
#define MAX_HATRED_PERSON       100

// �����˳�����ʱ��ÿ���Ƴ����ٸ�
#define HATREDP_REMOVED         10

mapping family_fame = ([
        "������"   : 10000,
        "�䵱��"   : 8000,
        "ؤ��"     : 7000,
        "ȫ���"   : 5000,
        "��ɽ��"   : 4000,
        "����μ�" : 4000,
        "����Ľ��" : 4000,
        "ѩɽ��"   : 3500,
        "���չ�"   : 3500,
        "������"   : 3000,
        "�һ���"   : 2500,
        "������"   : 2000,
        "��Ĺ��"   : 1500,
        "������"   : 1500,
        "��ң��"   : 1000,
        "����ɽ��" : 2000,
        "�������" : 1000,
        "����������" : 2000,        	
        "������"   : 2000, 	
        "��������" : 5000,
        "����" : 5000,
        "������" : 5000,
        "�嶾��" : 2000,
        "���ư�" : 3000,
        "����" : 3000,
        "������" : 3000,
        "�컨��" : 3000,
        "��ɽ��" : 4000,
        "̩ɽ��" : 2000,
        "�����" : 2000,
        "��ɽ��" : 2000,
        "��ɽ��" : 2000,
        "÷ׯ" : 1000,
        "�������" : 5000,        	
]);

// ����ID��Ӧ����������
static mapping family_name = ([
        "shaolin"  : "������",
        "wudang"   : "�䵱��",
        "gaibang"  : "ؤ��",
        "quanzhen" : "ȫ���",
        "huashan"  : "��ɽ��",
        "duan"     : "����μ�",
        "murong"   : "����Ľ��",
        "xueshan"  : "ѩɽ��",
        "lingjiu"  : "���չ�",
        "emei"     : "������",
        "taohua"   : "�һ���",
        "shenlong" : "������",
        "gumu"     : "��Ĺ��",
        "xingxiu"  : "������",
        "xiaoyao"  : "��ң��",
        "ouyang"   : "����ɽ��",
        "hu"       : "�������",
        "japan"       : "����������",
        "kunlun"       : "������",
        "nshaolin"       : "��������",
        "mingjiao"       : "����",
        "yunlong"       : "������",
        "wudu"       : "�嶾��",
        "tiezhang"       : "���ư�",
        "tangmen"       : "����",
        "lingxiao"       : "������",
        "honghua"       : "�컨��",
        "songshan"       : "��ɽ��",
        "taishan"       : "̩ɽ��",
        "qingchen"       : "�����",
        "henshan"       : "��ɽ��",
        "hengshan"       : "��ɽ��",
        "meizhuang"       : "÷ׯ",
        "riyue"       : "�������",
]);

mapping last_family_fame;

// ���ɶԳ��˳�޶ȵ�����
private int sort_hatred(string id1, string id2, mapping hatred);

void create()
{
        seteuid(getuid());
        restore();
        set_heart_beat(1800);
}

void remove()
{
        save();
}

public void mud_shutdown()
{
        save();
}

// ������ά�����ɵ�ͨ����Ϣ
private void heart_beat()
{
        int t;
        int last;
        string *all_fam;
        string fam;

        t = time();
        last = query("last_check");
        if ((t / 86400) != (last / 86400))
        {
                // ���������˱仯���������ɵ�������Ϣ
                all_fam = keys(family_fame) - ({ 0 });
                last_family_fame = family_fame;
                family_fame = ([ ]);

                foreach (fam in all_fam)
                        family_fame[fam] = last_family_fame[fam];
        }
        set("last_check", t);

        // �������ɵ�������Ϣ
        save();
}

// ���������������������Ϊ�գ�����mapping���ͣ�������������
// �ɵ������������������� �򷵻ظ��������ڵ��Ǹ����ɵ���
// ����������������ɣ��򷵻ظ����ɵ�������
public mixed query_family_fame(mixed ob)
{
        string fname;

        if (stringp(ob))
                return family_fame[ob];

        if (objectp(ob))
        {
                if (stringp(fname = ob->query("family/family_name")))
                        return family_fame[fname];
                else
                        return 0;
        }

        return family_fame;
}



// ��ѯ���������������Ϣ
public mapping query_all_last_family_fame()
{
        if (! mapp(last_family_fame))
                // û���������Ϣ�����ؽ����
                return family_fame;

        // �������������������Ϣ
        return last_family_fame;
}

// ��ѯ���ɵĳ����Ϣ�������ob���������ɵ����֣�Ҳ��������
// �е����
public mapping query_family_hatred(mixed ob)
{
        mapping hatred;
        string fname;

        if (objectp(ob))
                fname = ob->query("family/family_name");
        else
        if (stringp(ob))
                fname = ob;
        else
                fname = 0;

        if (! stringp(fname) || ! mapp(hatred = query("hatred/" + fname)))
                return 0;

        return hatred;
}

// �仯���������������ob���������ɵ����֣�Ҳ���������е���
// �
public void add_family_fame(mixed ob, int n)
{
        int new_fame;
        string fname;

        if (objectp(ob))
                fname = ob->query("family/family_name");
        else
        if (stringp(ob))
                fname = ob;
        else
                fname = 0;

        if (! stringp(fname) || undefinedp(family_fame[fname]))
                return;

        // �����µ���������
        new_fame = family_fame[fname] + n;
        if (new_fame < 0) new_fame = 0;
        if (new_fame > MAX_FAMILY_FAME)
                new_fame = MAX_FAMILY_FAME;
        family_fame[fname] = new_fame;
}

// ���ɼ��ɱ
public void family_kill(object killer, object victim)
{
        int kexp;
        int vexp;
        int a,b;
        string vfam;
        string kfam;
        string kid;
        int fame_delta;
        mapping hatred;
        mixed *d;

        // ֻ�����֮��ĳ�ɱ�ż�������

/*        if (! objectp(killer) || ! userp(killer) ||
            ! objectp(victim) || ! userp(victim))
                return;*/

          if (! objectp(killer) || ! objectp(victim) || ! userp(killer))
                return;

          if (! userp(victim) && ((int)victim->query("combat_exp")/3 < (int)killer->query("combat_exp")))
                return;


        // ��ʦ֮��ıȻ��ɲ�������
        if (wizardp(killer) || wizardp(victim))
                return;

        kexp = killer->query("combat_exp");
        vexp = victim->query("combat_exp");
        kfam = killer->query("family/family_name");
        vfam = victim->query("family/family_name");
//                                CHANNEL_D->do_channel(this_object(), "rumor",
//                                        "���ݿ�ʼ������");
        if (stringp(kfam) && kfam == vfam)
        {
                // ͬ�Ų�ɱ��
                return;
        }

        if (kexp < vexp * 3 && vexp >= 1000000)
        {
                // ɱ�ֵľ��鲻��ԶԶ�Ĵ��ڶԷ������ұ�ɱ��
                // ����һ���ľ��飬�⽫�������������Ľ��͡�
                fame_delta = vexp + killer->query("score") * 2 +
                             killer->query("weiwang") * 10;
                fame_delta /= 1000;
        } else
                // ���־���̫�٣����ǲ��̫�󣬲�Ӱ������
                fame_delta = 0;

        // �鿴ɱ�����ڵ������Ƿ������ߣ������ޣ����ܹ�
        // ���������ı仯��
        if (stringp(kfam))
        {
                string path;

                path = "hatred/" + kfam + "/" + victim->query("id");
                d = query(path);
                if (arrayp(d) && sizeof(d) >= 2 && intp(d[1]))
                {
                        // ������ߣ����ɻ�ö��������
                        if (d[1] > 2000)
                                CHANNEL_D->do_channel(this_object(), "rumor",
                                        "��˵" + killer->name(1) + "������" +
                                        victim->name(1) + "��Ϊ" +
                                        kfam + "�ֻ��˹�����");
                        fame_delta += d[1] / 3;

                        // �Դ��˵ĳ�޽���(���͵�Ҫ�����ӵ�Ҫ��)��
                        // ������Կ�fame_delta ���޶ȹ�˾�Ĳ���
                        d[1] -= fame_delta;
                        if (d[1] <= 0)
                                delete(path);
                        else
                                set(path, d);
                }
        }

        // �����������ɵ�����
        if (!userp(victim)) fame_delta=1;
        if (fame_delta> 10) fame_delta=10;
        a=FAMILY_D->query_family_fame(vfam);
//                              CHANNEL_D->do_channel(this_object(), "rumor",
//                                       kfam+"���ݴ�����"+a);
if (a > 0)
{
        add_family_fame(killer,  fame_delta);
        add_family_fame(victim, -fame_delta);
//                              CHANNEL_D->do_channel(this_object(), "rumor",
//                                       kfam+"���ݴ�����"+fame_delta);

}
        // ͳ�Ƹ�ɱ�ֶԱ��ŵĲк��̶�
        if (! stringp(vfam))
                return;

        // ��޳̶Ⱥ������ı仯������һ����������(K����)����
        // �ǳ�޳̶ȵ��������ı仯��
        vexp = vexp / 1000 + 1;
        if (vexp > 5000)
                vexp = (vexp - 5000) / 16 + 2000;
        else
        if (vexp > 1000)
                vexp = (vexp - 1000) / 4 + 1000;

        kid = killer->query("id");
        if (! mapp(hatred = query("hatred/" + vfam)))
        {
                set("hatred/" + vfam + "/" + kid,
                    ({ killer->name(), vexp }));
                return;
        }

        // ÿ����������¼���ɸ�����
        if (! undefinedp(d = hatred[kid]))
        {
                if (! arrayp(d) || sizeof(d) < 2 ||
                    ! intp(d[1]) || ! stringp(d[0]))
                {
                        // ���ID�����ݳ��˹���
                        d = 0;
                }
        } else
        if (sizeof(hatred) >= MAX_HATRED_PERSON)
        {
                string *ids;
                int i;

                // ����ȥ��һЩ�ˣ�Ϊʲô��ȥ��һ��������Ϊ
                // �˷�ֹ����Ƶ���Ľ��й��˲�����
                ids = sort_array(keys(hatred),
                                 (: sort_hatred :), hatred);
                for (i = 0; i < sizeof(ids) && i < HATREDP_REMOVED; i++)
                        map_delete(hatred, ids[i]);
        }

        if (! arrayp(d))
                d = ({ killer->name(1), vexp });
        else
        {
                d[0] = killer->name(1);
                d[1] += vexp;
        }

        // ��¼����˵���Ϣ
        hatred[kid] = d;
}

// ȥ���������ɶ�ĳ���˵ĳ����Ϣ
public void remove_hatred(string id)
{
        mapping all_hatred, hatred;
        string fam;

        if (! mapp(all_hatred = query("hatred")))
                // ���ڻ�û�г����Ϣ
                return;

        // �������е�����
        foreach (fam in keys(all_hatred))
        {
                if (mapp(hatred = all_hatred[fam]))
                        // ȥ�������ɶ�ĳ�˵ĳ����Ϣ
                        map_delete(hatred, id);

                if (! mapp(hatred) || ! sizeof(hatred))
                        // ��������Ѿ�û�г����Ϣ
                        map_delete(all_hatred, fam);
        }
}

// ��������
private int sort_hatred(string id1, string id2, mapping hatred)
{
        mixed *d1, *d2;

        if (! arrayp(d1 = hatred[id1]) || sizeof(d1) < 2 || ! intp(d1[1]))
                return -1;

        if (! arrayp(d2 = hatred[id2]) || sizeof(d2) < 2 || ! intp(d2[1]))
                return 1;

        return d1[1] - d2[1];
}

public string query_family_name(string fid)
{
        string fam;

        if (undefinedp(fam = family_name[fid]))
                fam = fid;
        return fam;
}

public mapping query_all_family_name()
{
        return family_name;
}

public string query_save_file() { return DATA_DIR "familyd"; }
