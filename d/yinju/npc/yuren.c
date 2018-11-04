inherit NPC;
#include <ansi.h>

void create()
{
	set_name("�������", ({ "diancang yuyin", "yu" }));
	set("title",  "�����ˮ������" );
	set("long", 
"�����Ǵ������ԭˮ��������һ�ƴ�ʦ���Ĵ����֮һ��
��ԼĪ��ʮ������ͣ�һ�ź�����Ĺ����������������
����������\n");
              set("nickname", HIY "���Ը���" NOR );   
        set("gender", "����");
        set("age", 55);
          set("long", 
        "�����ǵ������������־�ͳ�졣һ�ƴ�ʦ���£��������Ը����е���λ�棬
��׸���������˫��һ����������ˮ�档\n");


        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 25);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);     
        set("max_qi", 11000);
        set("max_jing", 11500);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("score", 100000);

        set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 150);
        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("cuff", 180);
        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
        ]) );
       map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("cuff",  "jinyu-quan");  
        map_skill("parry", "jinyu-quan");
        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);

        setup();
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
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	
	   switch(random(3))
	   {
		case 0:command("say �Ҷ���ʦ��������㣬��ô�졣");break;
	  	case 1:command("say �������ܵ��ٲ���ȥ����ô�졣");break;
	   	case 2:command("say �����㣬�����������ɡ�");break;
	   }
     
	
	return;
}

  int accept_object(object who, object ob)
{
   if (ob->query("id")=="jin wawa")
   {
      who->set_temp("give_wawa",1);
      command("say ��л�ˣ�");
      return 1;
   }
else
	message_vision("������ü��$N˵�����ܰ���׽����������\n", who);
        return 0;
}      
