
inherit NPC;

void create()
{
   set_name("����",({ "yi ren","yi","ren"}) );
   set("gender", "����" );
   set("age", 22);
   set("long", "����һλ�ںϷ��������������ˡ�\n");
       
   set("combat_exp", 50000);
   set("str", 25);
   set("per", 22);
   set_skill("unarmed",50);
   set_skill("parry",50);
   set_skill("dodge",50);
   
   set("chat_chance",20);
   set("chat_msg",({
    "����̾���������ѣ������ѣ��������˸��Ѱ���\n",
    "���˺�������Ǯ������Ǯ����ûǮ�������˳�������λ�׳��ˣ�\n",
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void die()
{
	message_vision("$N���������������յĶ�ɱ�����������Ź��㣡\n",this_object());
	return ::die();
}

