
inherit NPC;
void create()
{
   
   set_name("����",({ "yiren"}) );
        set("gender", "����" );
        set("age",25);
   set("long", "����һ�����յ����ˡ�\n");
   set("combat_exp",5000);
   set("str",25);
   set("chat_chance",60);
   set("chat_msg",({
      "���˸����е��������ı����ģ���Ǯ������Ǯ����ûǮ�������˳��ˣ�\n",
      "���˸����ȵ����������ˣ����Ե��湦���ˣ�\n",
   	}));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
