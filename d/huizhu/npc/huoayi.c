inherit NPC;
void create()
{
   set_name("������",({"huo ayi"}));
   set("gender","����");
   set("long","ľ׿�׵Ķ���,�ڻ����кܸߵ�����!\n");
   set("mingwang",160000);
   set("combat_exp",400000);
   set("area_name","������Ⱥ");
   
set("age",29);
   set("kee",1000);
   set("max_kee",1000);
set("food",250);
set("water",250);
   set("force",500);
   set("max_force",500);
   set("force_factor",30);

   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("whip",80);
   set_skill("sword",80);
   set_skill("club",120);

   setup();
   add_money("silver",30);
carry_object(__DIR__"obj/tiejia")->wear();
carry_object(__DIR__"obj/tieqiang")->wield();
}
