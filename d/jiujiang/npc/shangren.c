
inherit NPC;

void create()
{
   set_name("����",({ "shang ren","shang","ren" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǹ����ϴ��������ˡ�\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

