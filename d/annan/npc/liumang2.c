
inherit NPC;

void create()
{
   set_name("��åͷ��",({ "liu mang","liu","mang" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "����һ�����ϳ��ڵ���åͷ�ӡ�\n");
       
   set("combat_exp", 70000);
   set("str", 23);
   set("per", 18);
   set("attitude", "peaceful");
   set("chat_chance",50);
   set("chat_msg",({
	   "��åͷ˵���������������˵���㣡\n",
	   "��åͷ�������������������ʲô����\n",
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

