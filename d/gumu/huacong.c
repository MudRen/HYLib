// huacong.c
// By River@SJ 98/08/29
#include <ansi.h>
inherit ROOM;

void delete_hexiu(object me, object arg);

void create()
{
          set("short",HIR"�컨��"NOR);
          set("long", @LONG
��Ժ컨�ſ����������ɣ����ܲ�㣬�����˱ǣ�������������һ������
�磬�����֦��ɷ�Ǻÿ������������񴹸ǣ�������Ȼ��ɵ�һ���������ݡ�
���ܶ���һƬ���ģ�ֻ��Ȫ����������˼���ȷ�Ǹ��Ϻõ��������ڡ�
LONG        );

          set("exits", ([
               "east" : __DIR__"gmguoyuan",
          ]));

          set("outdoors","��Ĺ");

          set("no_fight", 1);
          setup();
}

void init()
{
        add_action("do_hexiu", "hexiu");
        add_action("do_quit", "quit");
}

int do_hexiu(object arg)
{
        object me = this_player();
        object ob, *inv;
        mapping fam;
        int ynlvl,i;

        if (me->is_busy() || me->is_fighting())
            return notify_fail("����æ���ء�\n");
        if (!arg)
            return notify_fail("��Ҫ��˭�����ڹ���\n");
        if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
            return notify_fail("�㲻�ǹ�Ĺ�ɴ��ˣ���ô������Ĺ���ڹ���\n");
        if (me->query("gender") == "����")
            return notify_fail("���޸����ԣ������������������������Ů�ľ��񹦡�\n");
        if (!(ob = present(arg, this_object())))
            return notify_fail("�������ڲ������\n");
        if ( me == ob)
            return notify_fail("������˫�ֻ�����\n");
        if (!living(ob))
            return notify_fail("������Ȱ�" + arg->name() + "Ū�ѡ�\n");
        if (!userp(ob))
            return notify_fail("��ֻ������Һ���������\n");
        if( me->query_temp("weapon"))
            return notify_fail("������������������ô˫����ԣ�������Ů�ľ���\n");
        ynlvl = me->query_skill("yunv-xinfa",1);
        if ( ynlvl > 150 )
            return notify_fail("���Ѿ����ܴӺ����еõ������ˣ�\n"); 

        if ( me->query("potential") < 1 )
            return notify_fail("���Ǳ�����Ĺ��ˣ���ʱ�޷����ޡ�\n");
        if( ob->query("potential") < 1)
            return notify_fail( ob->name()+"��Ǳ�����Ĺ��ˣ���ʱ�޷����ޡ�\n");
        if ( (int)me->query("potential") - (int)me->query("learned_points")  < 1 )
            return notify_fail("���Ǳ�����Ĺ��ˣ���ʱ�޷����ޡ�\n");
        if( (int)ob->query("potential") - (int)ob->query("learned_points")  < 1)
            return notify_fail( ob->name()+"��Ǳ�����Ĺ��ˣ���ʱ�޷����ޡ�\n");

        if ( ob->query_skill("yunv-xinfa", 1) < (ynlvl - 25))
            return notify_fail(ob->name() +"�����������̫Զ���޷�����������\n");
        if (me->query("jing") < 30 || me->query("qi") < 30)
            return notify_fail("��̫���ˣ���������Ϣһ����ɣ�\n");
        if (ob->query("jing") < 30 || ob->query("qi") < 30)
            return notify_fail(ob->name()+"̫���ˣ���������Ϣһ����ɣ�\n");
        if (me->query_temp("gumu_hexiu")
         && me->query_temp("gumu_hexiu")!= ob->query("id"))
            return notify_fail("����������˺����أ�\n");
        inv= all_inventory(me);
        i = sizeof(inv);
        while (i--)
        if( inv[i]->query("equipped") && ! inv[i]->query_autoload())
            return notify_fail("����㲻��ȥ�����������������п��ܻ��߻���ħ��\n"); 

        me->set_temp("gumu_hexiu", ob->query("id"));

        tell_object(ob,me->name()+"����������ǰ�������������Ů�ľ���\n");
        tell_object(me,"�������"+ob->name()+"��ǰ�������������Ů�ľ���\n");

        if ( ob->query_temp("gumu_hexiu") 
          && ob->query_temp("gumu_hexiu") != me->query("id"))
           return notify_fail(ob->name()+"û��Ҫ���������������˼��\n");
        if (!ob->query_temp("gumu_hexiu")) return 1;
        message_vision(HIW"\n$N���͸�����ԣ���$n������֣����˸�������һ�ߣ��⿪��������ϰ������\n"NOR,me, ob);
        me->start_busy(10);
        ob->start_busy(10);
        call_out("delete_hexiu",5, me, ob);
        return 1;
}

void delete_hexiu(object me, object ob)
{
        if ( !me || !ob) return;
        me->delete_temp("gumu_hexiu");
        ob->delete_temp("gumu_hexiu");
        me->start_busy(1);
        ob->start_busy(1);
        message_vision(HIR"\n$N��$n�ܵ���Ӧ����ʱ�˹�Ϊ����ȫ���������ڣ��ջ��ķᡣ\n\n"NOR,me,ob);
        me->receive_damage("jing", 20+random(10));
        me->receive_damage("qi",  20+random(5));
        me->add("potential", -1);
        me->improve_skill("yunv-xinfa", me->query_int()*( 2 + random(2)));        
        ob->receive_damage("jing", 20+random(10));
        ob->receive_damage("qi",  20+random(5));
        ob->add("potential", -1);
        ob->improve_skill("yunv-xinfa", ob->query_int()*( 2 + random(2))); 
        return;
}

int do_quit()
{
        write("���ﲻ׼�˳���\n");
        return 1;
}
