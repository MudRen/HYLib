// zhike.c ֪��

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIM"����"NOR, ({ "riyue hufa", "hufa" }));
        set("long",
                "������������󻤷���\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("no_get", 1);
        set_temp("no_kill", 1);

        set("str", 40);
        set("int", 40);
        set("con", 45);
        set("dex", 40);

        set("max_qi", 8000);
        set("max_jing", 8000);
        set("neili", 13000);
        set("max_neili", 13000);

        set("combat_exp", 800000);
        set("score", 1000);

        set_skill("force", 160);
        set_skill("dodge", 140);
        set_skill("unarmed", 140);
        set_skill("parry", 140);
        set_skill("sword", 140);
        set_skill("wudang-jian", 220);
        set_skill("taoism", 220);

        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");
        set_temp("apply/attack", 120);
        set_temp("apply/defense",450);
        set_temp("apply/armor", 450);
        set_temp("apply/damage", 100);

        create_family("�������", 3, "�󻤷�");
        set("chat_chance",2);
        set("chat_msg", ({
            "�󻤷�˵��������йٱ���ץ�ҽ̵��ӣ��ҵ�һ��Ҫ���Ļ���(huwei)������˿��и����\n"
        }));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_volunteer","huwei");
}

void greeting(object ob)
{
        mapping myfam;

        myfam = (mapping)ob->query("family");
        if(!myfam || myfam["family_name"] != "�������")
              say ("�󻤷������˵����λ"+RANK_D->query_respect(ob) + "����Ҫ���������ˡ�\n");
        else
              say ("�󻤷������˵����λ"+RANK_D->query_respect(ob) + "���������м����ӣ�����ɽ�ɡ�\n");
        return;

}


int do_volunteer()
{
        object me=this_player();
        object* ob;
        int i;

        if(me->query_condition("riyuejob")>0)
           return notify_fail("�󻤷�����˵��������Ϣһ��������\n");

        if (me->query_temp("in_guard")) 
           return notify_fail("�󻤷�����˵����ר���غ�ƽ���ݣ���������ݹ���\n");

        if( me->query("family/family_name") != "�������")
           {
            message_vision("�󻤷����һ���������������ģ���û�����㣡\n", me);
                      return 1;
           }


        if (me->query_temp("in_guard")) 
           return notify_fail("�󻤷�����˵����ר���غ�ƽ���ݣ���������ݹ���\n");

        ob = users();
        for (i=sizeof(ob); i>2; i--)
        {
                if (ob[i-1]->query_temp("in_guard"))
                return notify_fail("�󻤷�����˵���Ѿ�������ƽ���ݻ����ˣ���һ�������ɡ�\n");
        }
        tell_room(environment(me),me->query("name")+"��ʼ��ƽ���ݻ���ֵ�ء�\n");
	me->set("guard", HIG"���»���"NOR);
        me->set_temp("in_guard",1); 
        me->save();
        remove_call_out("end_guard");
        call_out("end_guard", 150, me);
        remove_call_out("clone_meng");
        call_out("clone_meng", 30, me);
        return 1;
}
void clone_meng(object me)
{
        object ob;
	int maxskill;
	int maxexp;
	maxskill=me->query_skill("force");
	maxexp=me->query("combat_exp");
        tell_room(environment(me),"ɽ��ͻȻ������һ��ٱ���\n");
        ob=new("/quest/menpaijob/riyue/mengmian.c");
        ob->move("/d/heimuya/pingdingzhou");
        ob->set("combat_exp",maxexp);
        ob->set_skill("kuang-jian",maxskill);
        ob->set_skill("sword",maxskill);
        ob->set_skill("parry",maxskill);        
        ob->set_skill("unarmed",maxskill);
        ob->set_skill("dodge",maxskill);        


	ob->set("title",HIR"�ٸ�����"NOR);
	ob->kill_ob(me);
	message_vision(HIR"\n$N����$n���һ����ɱ��!��\n"NOR,ob,me); 
        ob=new("/quest/menpaijob/riyue/mengmian.c");
        ob->move("/d/heimuya/pingdingzhou");
        ob->set("combat_exp",maxexp);
        ob->set_skill("kuang-jian",maxskill);
        ob->set_skill("sword",maxskill);
        ob->set_skill("parry",maxskill);        
        ob->set_skill("unarmed",maxskill);
        ob->set_skill("dodge",maxskill);        


	ob->set("title",HIR"�ٸ�����"NOR);
	ob->kill_ob(me);
	message_vision(HIR"\n$N����$n���һ����ɱ��!��\n"NOR,ob,me); 

        ob=new("/quest/menpaijob/riyue/mengmian.c");
        ob->move("/d/heimuya/pingdingzhou");
        ob->set("combat_exp",maxexp + 10000);
        ob->set_skill("kuang-jian",maxskill);
        ob->set_skill("sword",maxskill);
        ob->set_skill("parry",maxskill);        
        ob->set_skill("unarmed",maxskill);
        ob->set_skill("dodge",maxskill);        


	ob->set("title",HIG"�ٸ���ͷ"NOR);
	ob->kill_ob(me);
	message_vision(HIR"\n$N����$n���һ����ɱ��!��\n"NOR,ob,me); 


        call_out("clone_meng", 100, me);
}
void end_guard(object me)
{
        me->delete("guard");
        me->add("combat_exp",random(620) + 80);
        me->apply_condition("riyuejob",1+random(5));
        me->add("potential",random(320) + 80);
        me->delete_temp("in_guard"); 
        me->save();
        remove_call_out("clone_meng");
        tell_room(environment(me),me->query("name")+"��ƽ���ݻ�������������\n");
        tell_object(me,HIG"����ƽ���ݻ�����������������书������!\n");
}
void die()
{
        object *me;
        int i;

        me = users();
        for (i = 0; i < sizeof(me); i ++)
            me[i]->delete_temp("in_guard"); 

        ::die();
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
}
