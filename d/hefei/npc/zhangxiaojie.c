
inherit NPC;

void create()
{
   set_name("��С��",({ "xiao jie","xiao","jie" }) );
   set("gender", "Ů��" );
   set("age", 18);
   set("long", "�����Ų÷��Ů����\n");
       
   set("combat_exp", 10000);
   set("str", 14);
   set("per", 25);
   
   setup();

   add_money("coin", 1000);
}
