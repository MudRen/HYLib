#include <ansi.h>
inherit NPC;
int have_yuzhuo=1;

void create()
{
	set_name("����", ({ "bilian","girl", "xiaojie" }));
	set("age", 16);
	set("gender", "Ů��");
	set("attitude", "peaceful");
	set("str", 34);
	set("dex", 36);
       set("title","С��");
	set("combat_exp", 100000);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("force", 80);


    set("chat_chance", 7);
	set("chat_msg", ({
		"��,�´������ڲ���,Ϊ����������!\n",
		"����̧ͷ���Ŵ���,һ������,�ƺ�������ʲô.\n",
	}));
	set("inquiry", ([
		"����" : "��,���첻֪�����Ķ��ˣ�",
		"�㳦��" : "����,�⼸����������������!",
		]) );	
	setup();
add_money("gold",1);
	carry_object("/clone/weapon/changjian")->wield();
carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who,object item)
{	
	if(item->query("id")=="biyuzan")
	{if (have_yuzhuo==1)
	   {  command("say ��,���ҵ�����.....��лл��,���С�����͸��㡣\n");
message_vision("С���$Nһֻ"+HIC+"������.\n"NOR,who);
clone_object(__DIR__"obj/cuiyuzhu.c")->move(who);
have_yuzhuo=0;		
return 1; }
       else command("say ��,��������,�����Ѿ�������������!\n");
       return 0;
	}
	command("say ���ֲ����ҵĶ���,���Ҹ�ʲô��\n");
	return 0;
}
