// zhike.c ֪��

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("֪�͵���", ({ "zhike daozhang", "lingxu daozhang", "lingxu", "zhike" }));
        set("long",
                "���������飬���䵱ɽ��֪�͵�����\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("no_get", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_qi", 7000);
        set("max_jing", 7000);
        set("neili", 13000);
        set("max_neili", 13000);

        set("combat_exp", 200000);
        set("score", 1000);

        set_skill("force", 160);
        set_skill("dodge", 140);
        set_skill("unarmed", 140);
        set_skill("parry", 140);
        set_skill("sword", 140);
        set_skill("wudang-jian", 220);
        set_skill("taoism", 220);
	set_skill("taiji-shengong", 180);
	set_skill("dodge", 180);
	set_skill("tiyunzong", 180);
	set_skill("unarmed", 90);
	set_skill("taiji-quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 100);
	set_skill("wudang-array", 100);
	set_skill("array",100);
	set_skill("taoism", 100);
	set_skill("literate", 100);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);


        create_family("�䵱��", 3, "����");
        set("chat_chance",2);
        set("chat_msg", ({
            "֪�͵���˵�������䵱�����˽ܣ����ʢ�������µ��˶������ݾ��㡣\n",
            "֪�͵���˵�������������䵱�����Ż����ҵ�һ��Ҫ��������(volunteer)������˿��и����\n"
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
        add_action("do_volunteer","volunteer");
}

void greeting(object ob)
{
        mapping myfam;

        myfam = (mapping)ob->query("family");
        if(!myfam || myfam["family_name"] != "�䵱��")
              say ("֪�͵���Ц�����˵����λ"+RANK_D->query_respect(ob) + "����ӭ���䵱���������ȱ��裬ЪЪ�Ȱɡ�\n");
        else
              say ("֪�͵���Ц�����˵����λ"+RANK_D->query_respect(ob) + "��һ·�����ˡ�\n");
        return;

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}

int do_volunteer()
{
        object me=this_player();
        object* ob;
        int i;

        if(me->query_condition("wudangjob")>0)
           return notify_fail("֪�͵�������˵��������Ϣһ��������\n");

        if (me->query_temp("in_guard")) 
           return notify_fail("֪�͵�������˵����ר���غ�ɽ�ţ���������ݹ���\n");
        ob = users();
        for (i=sizeof(ob); i>3; i--)
        {
                if (ob[i-1]->query_temp("in_guard"))
                return notify_fail("֪�͵�������˵���Ѿ��в�������ɽ���ˣ���һ�������ɡ�\n");
        }
        tell_room(environment(me),me->query("name")+"��ʼ���䵱ɽ��ֵ�ء�\n");
	me->set("guard", HIG"ɽ������"NOR);
        me->set_temp("in_guard","1"); 
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
        tell_room(environment(me),"ɽ��ͻȻ������һ������󺺡�\n");
        ob=new("/d/wudang/npc/mengmian.c");
        ob->move("/d/wudang/xuanyuegate");
        ob->set("combat_exp",maxexp);
        ob->set_skill("kuang-jian",maxskill);
        ob->set_skill("sword",maxskill);
        ob->set_skill("parry",maxskill);        
	ob->set("title",HIR"�����"NOR);
	ob->kill_ob(me);
	message_vision(HIR"\n$N����$n���һ����ɱ��!��\n"NOR,ob,me); 
        call_out("clone_meng", 100, me);
}
void end_guard(object me)
{
        me->delete("guard");
        me->add("guarded",1);
        me->add("combat_exp",random(220) + 80);
        me->apply_condition("wudangjob",1+random(5));
        me->add("potential",random(200) + 80);
//        if ((int)me->query("potential")-(int)me->query("learned_points")>10000)
//        me->set("potential",(int)me->query("learned_points")+10000);
        me->delete_temp("in_guard"); 
        me->save();
        remove_call_out("clone_meng");
        tell_room(environment(me),me->query("name")+"���䵱ɽ��ֵ����������\n");
        tell_object(me,"�����䵱ɽ��ֵ����������\n");
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
