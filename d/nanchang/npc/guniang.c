
inherit NPC;

void create()
{
   set_name("��������",({ "girl"}) );
   set("gender", "Ů��" );
   set("age",15);
   set("long", "����һ�����ϲ������Ĺ��\n");
       
   set("combat_exp",100);
   set("str", 10);
   set("per", 20);
   set("attitude", "peaceful");
   set("chat_chance",4);
   set("chat_msg",({
     "�������ﺰ�������ʵ��ʻ��ˣ�˭�򰡣���ժ���ʻ���\n",
     "��������˵�������ʻ����㰡��������һ���ɣ�\n",
     (:random_move:),
   }));
   set("inquiry",([
     "۶����":"���������ˣ�ȥ�����ɣ�\n",
     ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

