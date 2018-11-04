// d/yunhe/npc/shaogong3 ���ݴ���
// netkill /98/8/18


#include <ansi.h>


inherit NPC;
int  zuchuan();

void create()
{
        set_name("����", ({ "chuan jia","jia",}));
	set("title","�˺ӿ���");
        set("gender", "����");
        set("age", 32);
        set("long",
        "����һ������Ĵ��ң��������˺�������ȽϺã����Կ���ȥ����\n"
        "�󱥾���ˬ���ˣ������Ҫ�⴬��������������\n",
            );

        set("combat_exp", 1000000);
        set("shen_type", 1);

        set("eff_qi",2000);
        set("qi",2000);
        set("max_neili", 1000);
        set("neili", 500);
        set("jiali", 10);

        set_skill("force", 90);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set("inquiry", ([
                
                   "�⴬" :   (: zuchuan :),

        ]) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
 }

void init()
{
	object ob;
        ::init();
        add_action("do_answer","answer");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query_temp("exit"))
	{
	message_vision("\n����Ц�����Ķ�$N˵������ӭ�������ݣ�һ·�ϻ�����ɡ�\n",ob);
	ob->delete_temp("exit");
	}
	else
	switch( random(2) ) {
		case 0:
			command("say ��λ�͹٣��ǲ���Ҫ����С������" );
			break;
		case 1:
			command("say �����˺ӿ��˵Ĵ����ֿ����������Ǯ��������һֻ�ɡ�"); 
			break;
	}
}


int zuchuan()
{
  object ob ;
  ob = this_player ( ) ;
  message_vision( "����������Ц�Ķ�$N˵����˵����˵!С��һֻ��ʮ����������һ�ˡ�\n" ,ob);
  ob->set_temp ("zu" , 1 );
  return 1;
}

int accept_object(object who, object ob)
{  
	if (!(int)who->query_temp("zu")&&ob->query("money_id") )
	{
         message_vision( "����Ц������ò˻�һ������$N˵�����͹����Ǵ󷽣����ƺ�ʩ���Ǹ����˰���\n",who);
        return 1;
	}
    if (ob->query("money_id") && ob->value() >= 2000) 
	{ 
	
	 tell_object(who, "���Ҷ���˵�����ã��ã�С�����ϸ������ã����Ժ\n"+
			    "������֪�͹��뵽�����أ�С�ĺø���׼����\n"+
			    "�ҿ�������ȥ�ĵط���:���ǡ����ݡ���ɽ�壬��͹���ʾ(answer)\n");
        this_player()->delete_temp("zu" );
	this_player()->set_temp("ok",1);
	return 1;
         }
   else  
         message_vision("���Ҳ����˵Ķ�$N˵����ò��Ǵ��ͽл��Ӱɡ�\n",who);       
	 return 1;
}
int do_answer( string arg )
{	
	object me;
	me=this_player();
	if (!(int)me->query_temp("ok") || arg=="����")
		
		  return notify_fail("���Ҷ���˵��������˵ʲô���ﻨ�㣬���⴬�Ļ��Ϳ���\n");
	
	else {	
	if (!arg || arg=="") 
	
		return notify_fail("���ҵɴ��ۿ�����˵:�͹��������˵��\n");
	
	switch (arg){
		case "����" : me->set_temp("exit",10);break;
		case "����" : me->set_temp("exit",45);break;
		case "��ɽ��" : me->set_temp("exit",25);break;
		default : return notify_fail("����Ц˵�����͹�˵Ц���Ҵ�С���������߳��󣬴�û��˵������ط�!\n");
		}
	me->set_temp("ok1",1);
	message_vision( "����Ц������˵�����úã����Ҹ���׼���ô���\n"+
			"˵��������˻��֣�����������������������\n\n"+
			"ֻ��һҶС�ۻ������˹�����\n"
			"����˵������׼���ϴ�(enter chuan)��!\n", me);
	
	}
        return 1;
}

