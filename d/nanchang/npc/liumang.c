
inherit NPC;

void create()
{
   set_name("��å",({ "liu mang","liu","mang" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "�����ϲ��������쵽���������ǵ���å��\n");
       
   set("combat_exp", 30000);
   set("str", 23);
   set("per", 22);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
	   "��åЦ�����ϲ����ڣ�˭�Ҳ����ҵ��ʣ�\n",
		   (:random_move:),
	   "��å��������˿���ĭ��������վ�ţ�\n",
       "��åһ��ţ������ǲ��ǻ�ˣ������ҹ�����\n",
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   add_money("coin",80);
  
}

