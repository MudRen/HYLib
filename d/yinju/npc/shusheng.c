#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_reply1();
string ask_reply2();
string ask_reply3();

void create()
{
	set_name("������", ({ "zhu ziliu", "zhu", "ziliu" }));
	set("title",  "�����������" );
	set("long", 
"�����Ǵ������ԭ�����࣬һ�ƴ�ʦ���Ĵ����֮һ��
ֻ������ʮ������ͣ�ͷ����ң���ֻ��۵��ȣ����
һ����ڵĳ��룬ȷ�Ǹ���ѧ����ģ����\n");
        set("nickname", HIY "���Ը���" NOR );
        set("gender", "����");
        set("age", 45);

       set("age", 45);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 35);
        set("dex", 35);
        
        set("max_qi", 11500);
        set("max_jing", 11500);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 100);
        set("combat_exp", 1800000);
        set("score", 200000);

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 175);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 155);
        set_skill("duanjia-sword", 150);
        set_skill("literate", 150);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("sword", "duanjia-sword");
        map_skill("staff", "duanjia-sword");
        map_skill("parry", "duanjia-sword");
        map_skill("cuff", "jinyu-quan");
        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);
        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档�����˾Ϳ��Լ����ˡ�\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
                "��δ״Ԫ"   : (: ask_reply1 :),
                "˪���Ҷ�����Ź����ң��"   : (: ask_reply2 :),
                "�������ˣ���С����Զǳ�"   : (: ask_reply3 :),
        ]) );
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
 add_action("do_answer", "answer");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        command("say ��������ɪ���ã��˴���һ��ͷ�档��������ʲô");

        if (ob->query_temp("help_nongfu"))
           ob->delete_temp("help_nongfu");
	return;
}
int do_answer(string arg)
{
      object me=this_player();
          if( arg=="�������ˣ���С����Զǳ�")
        {
            me->set_temp("answer_shusheng",1);  
          command("say �öԣ��öԣ���ȥ�ա�\n");
         }
         else 
             command("say ���ˣ���Դ��ˡ�\n");
        return 1;
}
        
string ask_reply1()
{
	object me = this_player();
	me->set_temp("yideng_du1", 1);
	if (me->query_temp("yideng_du2") && me->query_temp("yideng_du3"))
	{
message_vision("\n�������󾪣�վ������������һ�ӣ���$NһҾ���أ�˵���������°ݷ�����\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "�롣";
	}
	else
		return RANK_D->query_respect(me) + "��Ȼ����ȫ�š����������أ�";
}
string ask_reply2()
{
	object me = this_player();
	me->set_temp("yideng_du2", 1);
	if (me->query_temp("yideng_du1") && me->query_temp("yideng_du3"))
	{
message_vision("\n�������󾪣�վ������������һ�ӣ���$NһҾ���أ�˵���������°ݷ�����\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "�롣";
	}
	else
		return RANK_D->query_respect(me) + "��Ȼ����ȫ�š����������أ�";
}
string ask_reply3()
{
	object me = this_player();
	me->set_temp("yideng_du3", 1);
	if (me->query_temp("yideng_du1") && me->query_temp("yideng_du2"))
	{
message_vision("\n�������󾪣�վ������������һ�ӣ���$NһҾ���أ�˵���������°ݷ�����\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "�롣";
	}
	else
		return RANK_D->query_respect(me) + "��Ȼ����ȫ�š����������أ�";
}
