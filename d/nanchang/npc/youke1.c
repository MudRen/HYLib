
inherit NPC;

void create()
{
   set_name("�ο�",({ "you ke","you","ke"}) );
   set("gender", "����" );
   set("age", 32);
   set("long", "����һ�����ϲ��۹���ο͡�\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("chat_chance",30);
   set("chat_msg",({
	   "�ο�˵����������ϲ���һ��Ҫ�úõ���һ�ˣ�\n",
	   "�ο�̾��������������ϣ��������ң���֪��ʲôʱ���������ϲ��ˡ�\n",
	   "�ο�˵�����������Ů���������ף���Ҳ����ȥ���԰���\n",
	   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

