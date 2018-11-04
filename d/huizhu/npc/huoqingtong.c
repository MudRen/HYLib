inherit NPC;
void create()
{
   set_name("»ôÇàÍ©",({"huo qingtong"}));
   set("gender","Å®ÐÔ");
   set("long","Ä¾×¿Â×µÄ´óÅ®¶ù,¿¶¿®ºÀË¬,Å®ÖÐºÀ½Ü!\n");
   set("score",4000);
   set("combat_exp",150000);
   set("title","´äÓð»ÆÐä");
   set("area_name","»Ø×åÄÁÈº");
   
set("per",35);
set("age",21);
   set("qi",1000);
   set("max_qi",1000);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",30);

   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("unarmed",80);
   set_skill("whip",80);
   set_skill("sword",100);

   setup();
   add_money("silver",30);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/sword")->wield();
}
