#include <ansi.h>
inherit NPC;
void random_chat();
int answer();
void create()
{
     set_name("��������",({"dongtiao daxiong","dongtiao","daxiong"}));
   set("gender","����");
   set("age",47);
   set("combat_exp",20000);
    set("title","���õ�");
   set_skill("unarmed",10);
   set_skill("dodge",10);
   set_skill("force",10);
   set_skill("parry",10);
   set_skill("literate",10);
   
    set("chat_chance",8);
   set("chat_msg",({
   (:random_chat:),
}));
   
   
   set("inquiry",([
   "this emote":(:answer:),
   ]));
   
   setup();
   add_money("silver",30);
  carry_object("clone/misc/cloth")->wear();
}

void random_chat()
{
  string *e,str="";
   int i;
   object npc,*inv;
   
   inv=all_inventory(environment(this_object()));
	if(!sizeof(inv))	return;
 
   e = sort_array(EMOTE_D->query_all_emote(), 1);
   str=e[random(sizeof(e))];
   command(str+" "+inv[random(sizeof(inv))]->query("id"));
   set("answer",str);  
   return;
}
int answer()
{
 command("say ���emoteô,��("+query("answer")+").\n");
 return 1;
 }
