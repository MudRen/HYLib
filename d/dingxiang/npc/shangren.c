
inherit NPC;
void create()
{
   
   set_name("����",({ "shang ren","shang","ren"}) );
        set("gender", "����" );
        set("age",50);
   set("long", "����һ�������ؾ��̵����ˡ�\n");
   set("combat_exp", 200000);
   set("str", 30);     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
