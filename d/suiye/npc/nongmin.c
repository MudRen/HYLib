
inherit NPC;
void create()
{
   
   set_name("ũ��",({ "nong min","nong","min"}) );
        set("gender", "����" );
        set("age",30);
   set("long", "����һ����ʵ��ũ��\n");
   set("combat_exp",5000);
   set("str",25);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
