
inherit NPC;

void create()
{
   set_name("С��",({ "xiao cui","xiao","cui"}) );
        set("gender", "Ů��" );
        set("age", 18);
   set("long", "����ӭ��¥�Ĺ��\n");
       
   set("combat_exp", 10000);
   set("str", 14);
   set("per", 26);
   set("attitude", "friendly");
   set("chat_chance",40);
   set("chat_msg",({
	   "С�使Ц�����ϣ���λ�͹٣������������\n",
	   "С��Ц�����ϣ��͹٣������ɣ��������⣡\n",
   }));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   add_money("coin", 50);
}

