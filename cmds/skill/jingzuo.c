// jingzuo.c
// Dec.11 1997 by Venus
#include <ansi.h>
void wakeup(object me, object where);
void del_jingzuoed(object me);

int main(object me, string arg)
{
        mapping fam;
        object where = environment(me);
       int lv = (int) me->query_skill("mahayana",1);
        seteuid(getuid());

        if ((!(fam = me->query("family")) || fam["family_name"] != "������"))
             return notify_fail("ֻ�ж����ɲ��ܾ�����\n");
//        if (where->query("no_sleep_room"))
//             return notify_fail("����̫���ӣ���û�����ľ�����\n");
	if( me->query_temp("dushi") )
		return notify_fail("���Ѿ���Ȱ�˼Ұն��ˣ�\n");

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

        if (where->query("sleep_room"))
             return notify_fail("����̫���ӣ���û�����ľ�����\n");
        if (me->query("eff_jing")<50)
             return notify_fail("������̫�أ�û��������\n");
        if (me->is_busy())
             return notify_fail("����æ���أ�\n");
        if (me->is_fighting())
             return notify_fail("ս�����뾲�����㲻Ҫ������\n");
	me->save();
        if (me->query("mud_age") - me->query_temp("jingzuo_time") < 80)
             return notify_fail("��ղž�����������ͷ��һƬ�հס�\n");
        if (me->query_skill("linji-zhuang",1) < 40)
             return notify_fail("����ټ�ʮ��ׯ��̫ǳ���ˣ�û�����ľ�����\n");
        if (me->query_skill("mahayana",1) < 40)
//       if (me->query("potential")-me->query("learned_points")>50000)
//             return notify_fail("���Ǳ��̫���ˣ�û�����ľ�����\n");

//        if (where->query("sleep_room"))
//        {
             write(HIC"����������ϥһ������ʼ������\n"NOR);
             write(HIC"����������ϥһ������ʼ������\n"NOR);
        write("����ϥ����������Ƭ�̱������һ���������\n");

             write(HIG"��һ��������������⣬����������\n"NOR);
        switch(random(4)) {
        case 0:
               write(HIW"
��ʱ����������˵�Ǿ��������Ȥ�����ᱯ�������׷��ԣ���ϣ�У���
�𣡷�˵��������䣬�Ҵ��������û��ۣ�δ����������֮��������
�������˵����Ǿ��������徻������ʵ�࣬��֪���ˣ��ɾ͵�һϣ�й�
�¡�������ʵ���ߣ����Ƿ��࣬�ǹ�����˵��ʵ�ࡣ�����ҽ����
���Ǿ��䣬�Ž��ֲܳ���Ϊ�ѣ�����������������꣬��������������
�Ǿ����Ž��֣ܳ�������Ϊ��һϣ�С����Թʣ����������ࡢ���ࡢ��
���ࡢ�����ࡣ�����ߺΣ����༴�Ƿ��࣬���ࡢ�����ࡢ������
���Ƿ��ࡣ���Թʣ���һ�����࣬������𡣡�           
 \n"NOR);
               break;
        case 1:
               write(GRN"
�������ᣡ���������ǡ��������ԣ����ҵ����������������������
�������Թʣ������ᣡ���з���Ϊ�������ǹʷ�˵��һ�з����ҡ����ˡ�
�������������ߡ������ᣡ�����������ԣ����ҵ�ׯ�Ϸ��������ǲ���
���������Թʣ�����˵��ׯ�Ϸ����ߣ�����ׯ�ϣ�����ׯ�ϡ������ᣡ
������ͨ�����ҷ��ߣ�����˵������������
\n"NOR);
               break;
        case 2:
               write(CYN"
�ƺ������������ӣ�һ����������ʼ�������ֵߵ����������ˣ��ķ���
���������Ĵ�Ϊ�����࣬����Ե��Ϊ�����ࡣƩ�˲�Ŀ�����л����ڶ�
�������ӣ���ʵ�޻���������ִ������ִ�ʣ���Ψ���������ԣ��ิ
�Ա�ʵ���������ɴ�������ת�����������������������ߣ�����ʵ�塣
�������ˣ���ʱ���ޣ�������ѣ��������á����ڿջ������գ�����
��˵�ж��𴦡����Թʣ��������ʣ�һ������������У�����������
��˵����ת������
\n"NOR);
               break;
        case 3:
               write(HIY"
�����ᣡ�����ȥ����������������ˣ��ڶ������������ࡢ�����ࡢ
�������ࡢ�������ࡣ�ǹ������ᣡ����Ӧ��һ���࣬�������������
�������ģ���Ӧסɫ���ģ���Ӧס����ζ�������ģ�Ӧ������ס�ġ���
����ס����Ϊ��ס���ǹʷ�˵�������Ĳ�Ӧסɫ��ʩ�������ᣡ����Ϊ
����һ��������Ӧ���ǲ�ʩ������˵��һ�����࣬���Ƿ��ࡣ��˵��һ
����������������������ᣡ�����������ߡ�ʵ���ߡ������ߡ���ڿ��
�ߡ��������ߡ������ᣡ�������÷����˷���ʵ���顣�����ᣡ������
��ס�ڷ����в�ʩ�������밵�������������������Ĳ�ס�ڷ����в�ʩ��
������Ŀ���չ����գ�������ɫ�������ᣡ����֮�������������ӡ���
Ů�ˣ����ڴ˾��ֶܳ��У���Ϊ�����Է��ǻۣ�Ϥ֪���ˣ�Ϥ�����ˣ�
�Եóɾ������ޱ߹��¡�
\n"NOR);
                break;
        }

             me->set_temp("block_msg/all",1);
             message_vision(HIC"$Nһ�������ڴ��ϣ���Ŀ������Ĵ�����\n"NOR,me);
             where->add_temp("jingzuo_person", 1);

             me->set("no_get", 1);
             me->set("no_get_from", 1);
             me->disable_player("<������>");
lv=lv/5;
if (lv<20) lv=20;
             call_out("wakeup",random(lv)+1 , me, where);

             return 1;
//        } else return notify_fail("����̫���ӣ���û�����ľ�����\n");
}

void wakeup(object me,object where)
{
       int skillslvl,addp,addc,exppot,intpot;
if (!me) return;
       skillslvl = (int) me->query_skill("mahayana",1);

//       exppot = (int)(me->query("combat_exp")/20000);
//       intpot = (int)(me->query_int()/10);
       addp = (int)(random(skillslvl)+10);
       addc = (int)(random(skillslvl)+15);
       me->add("jing",-15);
       me->add("eff_jing",-3);
if (addp > 130) addp=130;
if (addc > 180) addc=180;

       me->add("potential",addp);
       me->add("combat_exp",addc);
       me->start_busy(3);
       me->enable_player();

       message_vision(HIG"$N������ϣ��������ۣ���������һ������\n"NOR,me);
       me->set_temp("block_msg/all", 0);
       me->set_temp("jingzuo_time", me->query("mud_age"));
                write(HIW"
��֪���˶�ã������ڷ𷨵��������ȫ���עȥ������ָо�����
��Ȼ��ȴ��ʱ�䡣��������һ�ᣬ����Ƿ�������������غ���һ��    
��������ʱ��һ�ַ��ޱߵĸо���
\n"NOR);

       write(HIB"�㾲����ϣ����۵ĸо���\n"NOR);
   tell_object(me,HIW"�����ˣ�\n" + 
                       chinese_number(addc) + "��ʵս����\n" +
                       chinese_number(addp) + "��Ǳ��\n"+
                       NOR);

       where->add_temp("jingzuo_person", -1);
       me->delete("no_get");
       me->delete("no_get_from");
       return;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : jingzuo <������>

���ָ���Ƕ����ɵ������Ծ����޵�������.

HELP
        );
        return 1;
}
