
inherit NPC;
void create()
{
   
   set_name("�鱦��",({ "zhubao shang","shang"}) );
        set("gender", "����" );
        set("age",50);
   set("long", "����һ���鱦�̡�\n");
   set("combat_exp", 200000);
   set("str", 30);     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
