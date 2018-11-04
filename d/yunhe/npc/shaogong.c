// /d/npc/chuangfu
// netkill /98/8/18


#include <ansi.h>


inherit NPC;
int  zuchuan();

void create()
{
        set_name("����", ({ "chuan jia","jia",}));
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
        ::init();
        add_action("do_answer","answer");
	
}


int zuchuan()
{
  object ob ;
  ob = this_player ( ) ;
  message_vision( "����������Ц�Ķ�$N˵����˵����˵���͹�����ʲô���Ĵ��أ�\n"
                 "�촬һ�������ӣ�С��ʮ������ʲôǮ��ʲô������ƽ������\n" 
                 ,ob);
  ob->set_temp ("zu" , 1 );
  return 1;
}

int accept_object(object who, object ob)
{
    if (ob->query("money_id") && ob->value() >= 1000) 
	{ 
	if (!(int)who->query_temp("zu"))
         return notify_fail("����Ц������ò˻�һ����˵�����͹����Ǵ󷽣����ƺ�ʩ���Ǹ����˰���\n");
        tell_object(who, "���Ҷ���˵�����ã��ã�С�����ϸ������ã����Ժ\n"+
			    "������֪�͹��뵽�����أ�С�ĺø���׼����\n"+
			    "�ҿ�������ȥ�ĵط���:���ǡ����ݡ���ɽ�壬��͹���ʾ(answer)\n");
        this_player()->delete_temp("zu" );this_player()->set_temp("ok",1);
	return 1;
         }
    else  
        if (ob->query("money_id") && ob->value() < 1000 && (int)who->query_temp("zu"))
         message_vision("���Ҳ����˵�˵����ò��Ǵ��ͽл��Ӱɡ� \n");       
	 return 0;
	
 }

int do_answer( string arg )
{	
	object me;
	me=this_player();
	if (!(int)me->query_temp("ok"))
		
		  return notify_fail("���Ҷ���˵��������˵ʲô���ﻨ�㣬���⴬�Ļ��Ϳ���\n");
	
	else {	
	if (!arg || arg=="") 
	
		return notify_fail("���ҵɴ��ۿ�����˵:�͹��������˵��\n");
	
	switch (arg){
		case "����" : me->set_temp("exit",10);break;
		case "����" : me->set_temp("exit",40);break;
		case "��ɽ��" : me->set_temp("exit",20);break;
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

