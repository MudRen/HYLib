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

        set("str", 40);
        set("int", 40);
        set("con", 45);
        set("dex", 40);

        set("eff_qi", 30000);
        set("qi", 30000);
        set("jing", 30000);                
        set("eff_jing", 30000);                
        set("max_qi", 30000);
        set("max_jing", 30000);
        set("neili", 33000);
        set("max_neili", 33000);

        set("combat_exp", 800000);
        set("score", 1000);

        set_skill("force", 260);
        set_skill("dodge", 340);
        set_skill("unarmed", 240);
        set_skill("parry", 340);
        set_skill("sword", 240);
        set_skill("wudang-jian", 220);
        set_skill("taoism", 220);

        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");
        set_temp("apply/defense",450);
        set_temp("apply/armor", 800);

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
        add_action("do_finish","finish");
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

        if(me->query_condition("riyuejob"))
           return notify_fail("�󻤷�����˵��������Ϣһ��������\n");
        if(me->query_condition("guojob2_busy"))
           return notify_fail("�󻤷�����˵��������Ϣһ��������\n");
        if (me->query_temp("in_guard")) 
           return notify_fail("�󻤷�����˵����ר���غ�ƽ���ݣ���������ݹ���\n");
        if (this_object()->is_busy())
                return notify_fail("�󻤷�����˵�������ڲ��û������£����һ�ᡣ\n");

        if( me->query("family/family_name") != "�������")
           {
            message_vision("�󻤷����һ���������������ģ���û�����㣡\n", me);
                      return 1;
           }
        if( me->query("family/family_name") == "�������")
           {
             if ( me->query_skill("kuihua-xinfa",1) < 30
             ||  me->query_skill("tmdafa",1) < 30) 
             {
            message_vision("�󻤷����һ��������ȥѧһЩ���ŵ��ڹ�������\n", me);
                      return 1;
            }
           }

        if (me->query_temp("in_guard")) 
           return notify_fail("�󻤷�����˵����ר���غ�ƽ���ݣ���������ݹ���\n");
      if (me->query("guardry"))
           return notify_fail("�󻤷�����˵����ר���غ�ƽ���ݣ���������ݹ���\n");
      if (me->query_condition("riyue_guard"))
           return notify_fail("�󻤷�����˵����ר���غ�ƽ���ݣ���������ݹ���\n");

        ob = users();
        tell_room(environment(me),me->query("name")+"��ʼ��ƽ���ݻ���ֵ�ء�\n");
        set("qi", 30000);
        set("jing", 30000);
	me->set("guardry", HIG"���»���"NOR);
        me->set_temp("in_guard",1); 
        me->apply_condition("riyue_guard",12);
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
           return notify_fail("��������˵������æ����!\n");
if (me->is_fighting())
           return notify_fail("��������˵������æ����!\n");
        if (this_object()->is_busy())
                return notify_fail("�󻤷�����˵�������ڲ��û������£����һ�ᡣ\n");

      if (!me->query("guardry"))
           return notify_fail("��������˵��������������\n");
if (me->query_condition("riyue_guard"))
           return notify_fail("��������˵���������ڻ�û�е���!!\n");
if (me->query_condition("riyuejob"))
           return notify_fail("��������˵������Ϣһ������!!\n");

if (!me->query_temp("in_guard"))
           return notify_fail("��������˵��������������\n");
        me->delete("guardry");
        me->delete_temp("in_guard"); 
if (environment(me)->query("short")=="ƽ����"){
pot=random(400) + 250;
exp=random(620) + 280;
             me->add("potential",pot);
             me->add("combat_exp",exp);
        me->add("guarded",1);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->apply_condition("riyuejob",9);
        tell_room(environment(me),me->query("name")+"��ƽ���ݻ�������������\n");
        tell_object(me,"����ƽ���ݻ�������������\n");
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);

}
else {
        tell_room(environment(me),me->query("name")+"��ƽ���ݻ����߿���ʧ�ܡ�\n");
        tell_object(me,"����ƽ���ݻ����߿���ʧ�ܡ�\n");
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
