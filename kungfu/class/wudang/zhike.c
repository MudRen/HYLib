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
set("wdnpc",1);
        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("qi", 30000);
        set("jing", 30000);
        set("max_qi", 30000);
        set("max_jing", 30000);
        set("neili", 13000);
        set("max_neili", 13000);

        set("combat_exp", 1800000);
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
	set_skill("taiji-quan", 200);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 200);
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
	set_temp("apply/defense", 105);
	set_temp("apply/damage", 5);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 800);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
        }) );
        create_family("�䵱��", 3, "����");
        set("chat_chance",2);
        set("chat_msg", ({
            "֪�͵���˵�������䵱�����˽ܣ����ʢ�������µ��˶������ݾ��㡣\n",
            "֪�͵���˵�������������䵱�����Ż����ҵ�һ��Ҫ��������(volunteer)������˿��и����\n"
            "֪�͵���˵�������ֵ��ʱ�䣬�����������(finish)������˿��и����\n"
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
        add_action("do_finish","finish");
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

        if(me->query_condition("wudangjob"))
           return notify_fail("֪�͵�������˵��������Ϣһ��������\n");
        if(me->query_condition("guojob2_busy"))
           return notify_fail("֪�͵�������˵��������Ϣһ��������\n");

        if (this_object()->is_busy())
                return notify_fail("֪�͵�������˵�������ڲ�����ɽ�ŵ��£����һ�ᡣ\n");

        if (me->query_temp("in_guard")) 
           return notify_fail("֪�͵�������˵����ר���غ�ɽ�ţ���������ݹ���\n");

        if( me->query("family/family_name") != "�䵱��")
           {
             if ( me->query("guarded") > 10) 
             {
            message_vision("֪�͵������һ������Ϊ���ɵĵ��ӣ����Ѿ�Ϊ��������̫�����ˣ�\n", me);
                      return 1;
            }
           }
        if( me->query("family/family_name") == "�䵱��")
           {
             if ( me->query_skill("taiji-shengong",1) < 30) 
             {
            message_vision("֪�͵������һ��������ȥѧһЩ���ŵ��ڹ�������\n", me);
                      return 1;
            }
           }

      if (me->query("guardwd"))
           return notify_fail("֪�͵�������˵����ר���غ�ɽ�ţ���������ݹ���\n");
      if (me->query_condition("wudang_guard"))
           return notify_fail("֪�͵�������˵����ר���غ�ɽ�ţ���������ݹ���\n");


        if (me->query_temp("in_guard")) 
           return notify_fail("֪�͵�������˵����ר���غ�ɽ�ţ���������ݹ���\n");

        ob = users();
        tell_room(environment(me),me->query("name")+"��ʼ���䵱ɽ��ֵ�ء�\n");
        set("qi", 30000);
        set("jing", 30000);
	me->set("guardwd", HIG"ɽ������"NOR);
        me->set_temp("in_guard","1"); 
        me->apply_condition("wudang_guard",12);
        me->start_busy(2);
this_object()->start_busy(15);
        me->save();
        return 1;
}
int do_finish()
{
 int exp,pot;
        object me=this_player();
        object* ob;
        int i;
if (me->is_busy())
           return notify_fail("֪�͵�������˵������æ����!\n");
        if (this_object()->is_busy())
                return notify_fail("֪�͵�������˵�������ڲ�����ɽ�ŵ��£����һ�ᡣ\n");

if (me->is_fighting())
           return notify_fail("֪�͵�������˵������æ����!\n");
      if (!me->query("guardwd"))
           return notify_fail("֪�͵�������˵����������ֵ��\n");
if (me->query_condition("wudang_guard"))
           return notify_fail("֪�͵�������˵����ֵ���ڻ�û�е���!!\n");
if (!me->query_temp("in_guard"))
           return notify_fail("֪�͵�������˵����������ֵ��\n");
if (me->query_condition("wudangjob"))
           return notify_fail("֪�͵�������˵������Ϣһ������!!\n");

        me->delete("guardwd");
        me->delete_temp("in_guard"); 
if (environment(me)->query("short")=="������"){
pot=random(400) + 250;
exp=random(620) + 280;
             me->add("potential",pot);
             me->add("combat_exp",exp);
        me->add("guarded",1);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->apply_condition("wudangjob",7);
        tell_room(environment(me),me->query("name")+"���䵱ɽ��ֵ����������\n");
        tell_object(me,"�����䵱ɽ��ֵ����������\n");
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);

}
else {
        tell_room(environment(me),me->query("name")+"���䵱ɽ��ֵ���߿���ʧ�ܡ�\n");
        tell_object(me,"�����䵱ɽ��ֵ���߿���ʧ�ܡ�\n");
}

        set("qi", 30000);
        set("jing", 30000);
this_object()->start_busy(8);

        return 1;
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