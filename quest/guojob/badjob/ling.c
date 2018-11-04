// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);

void create()
{
        set_name("����", ({ "lingpai"}));
        set("long", "����");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 60);
                set("unit", "��");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","cisha");
}
int do_shouzhang(string arg)
{
object ob=this_object(),me=this_player();
string targ;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("��Ҫ��ɱ˭��\n");
        targ=ob->query("name");
if (userp(ob))
return notify_fail("�����ʲô!!\n");
        if ( targ != me->query_temp("menggu_job_target") )
return notify_fail("���Ǵ�ɱ"+me->query_temp("menggu_job_target")+"������!!\n");

         if(me->query_condition("menggu_mission")<=1)
                return notify_fail("�㲻�����������������\n");
        if (userp(ob)) return notify_fail("��Ū�����˰ɣ�\n");

        if (me->query_temp("mgjob")!=1)
                return notify_fail("�㲻�����������ȥ���ʡ�\n");
        message_vision(HIG"\n$N���������������!��\n"NOR,me);
	ob->set_temp("must_killby",me->query("id"));
        me->set_temp("mgjob",2);
       call_out("mgjob_1", 5, me, ob);
        return 1;
}

int mgjob_1(object me,object ob)
{
        object newob;

        newob = new(__DIR__"xiashi");
        newob->set("combat_exp",me->query("combat_exp") * 5 / 5);
        newob->set("max_qi",me->query("max_qi"));
        newob->set("eff_qi",me->query("max_qi"));
        newob->set("jiali", 60);
        newob->set("qi",me->query("max_qi"));
        newob->set("max_jingli",me->query("max_jingli"));
        newob->set("eff_jingli",me->query("max_jingli"));
        newob->set("jingli",me->query("max_jingli"));
        newob->set("max_neili",me->query("max_neili"));
        newob->set("neili",me->query("max_neili"));
        newob->set_skill("force", me->query_skill("force")*2/3);
        newob->set_skill("huifeng-jian", me->query_skill("force")*2/3);
        newob->set_skill("kunlun-shenfa", me->query_skill("force")*2/3);
        newob->set_skill("strike", me->query_skill("force")*2/3);
        newob->set_skill("kunlun-zhang",me->query_skill("force")*2/3);
        newob->set_skill("jinding-zhang",me->query_skill("force")*2/3);
        newob->set_skill("dodge", me->query_skill("force")*2/3);
        newob->set_skill("sword", me->query_skill("force")*2/3);
        newob->set_skill("linji-zhuang", me->query_skill("force")*2/3);
        newob->set_skill("parry", me->query_skill("force")*2/3);
        newob->set_skill("literate", me->query_skill("force")*2/3);
        newob->set("shen",(me->query("combat_exp")/20));
        newob->move(environment(me));
        message_vision("\n" + HIW + "$N��������ͷ��������!\n"NOR, me);
        message_vision("\n" + HIR + "$N��$n���һ���������������ԣ���������\n"NOR, me, newob);
        me->kill_ob(newob);
        newob->kill_ob(me);
        me->kill_ob(ob);
        ob->kill_ob(me);
        destruct(this_object());
}
