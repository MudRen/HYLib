
inherit NPC;

void create()
{
   set_name("��å",({ "liu mang","liu","mang" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "����һ�����ϳ��ڵ���å��\n");
       
   set("combat_exp", 50000);
   set("str", 23);
   set("per", 18);
   set("attitude", "peaceful");
   set("chat_chance",50);
   set("chat_msg",({
	   "��å˵���������������˵���㣡\n",
	   "��å���˿���ĭ����������������ʲô����\n",
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

