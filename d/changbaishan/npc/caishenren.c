
inherit NPC;

void create()
{
   set_name("�ɲ���",({ "man" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "����һ������ɽ�ɲε��ˡ�\n");
       
   set("combat_exp", 5000);
   set("str", 10);
   set("attitude", "peaceful");
   set("inquiry",([
      "�˲�":"��Ҫ�ɲ����ھͿ����ˣ�\n",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

