#include <ansi.h>
#include <combat.h>

inherit NPC;

#include "action.h"

string *cmds = ({"wield", "unwield", "wear", "remove", "enable", "jifa", "prepare", "bei", "exert",
"yun", "perform", "yong", "enforce", "jiali"});

void random_chat();
int ask_go();
int ask_kiss();
int ask_wait();
int ask_home();
int ask_eat();
int ask_fight();
int ask_fight1();
int ask_fight2();
int ask_fight3();

void exec_cmd(object me, string arg);
mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);
int check_legal_title(string name);
create_wine(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;
object me=this_player();
        obj = new(__DIR__"obj/wine");
        obj->set_name(cup, idlist);
        obj->set("guardfood",1);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", RED+"Ò»±­´¼ÕıµÄ" + nmstr + "¡£\n" + NOR);
        obj->set("liquid/name", nmstr);
write( HIG "¾Æ:"+nmstr+HIG"×öºÃÁË¡£"+"\n" NOR);
        obj->move(me);
}

create_water(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;
object me=this_player();
        obj = new(__DIR__"obj/water");
        obj->set_name(cup, idlist);
        obj->set("guardfood",1);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", YEL+"Ò»±­¿É¿ÚµÄ" + nmstr + "¡£\n" + NOR);
        obj->set("liquid/name", nmstr);
write( HIG "İ±:"+nmstr+HIG"ÂòºÃÁË¡£"+"\n" NOR);
        obj->move(me);
}

create_food(string nmstr, string* idlist, string longstr)
{
        object obj;
object me=this_player();
        obj = new(__DIR__"obj/food");
        obj->set_name(nmstr, idlist);
        obj->set("guardfood",1);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", GRN+"Ò»ÅÌÈÈÆøÌÚÌÚ, ÏãÅçÅçµÄ"+nmstr+"¡£\n"+NOR);
write( HIG "²Ë:"+obj->query("name")+HIG"×öºÃÁË¡£"+"\n" NOR);
        obj->move(me);
}
void create()
{
        set_name(HIW"±¦¶ù"NOR, ({ "shi tong",  "shitong"}));
	set("title", HIM "¾øÊÀ·ç»ª" NOR);
	set("long", HIG "Ëû¿´ÉÏÈ¥Ö»ÓĞÊ®À´Ëê£¬³¤µÃÕıÊÇÓñÊ÷ÁÙ·ç£¬äìÈ÷ÙÃÙÎ¡£\n"+
	"µ«ËûµÄË«Ä¿ÖĞÈ´°üº¬×ÅÒ»ÖÖÉîÉîµÄÓÇÓô£¬\n"+
	"ËÆºõÕıÔÚ¸ĞÌ¾ÈË¼ä²×É££¬ÊÀÊÂÎŞ³£¡£\n" NOR);
        set("marry","hxsd");
        set("gender", "ÄĞĞÔ");
 	set("age", 18);
        set("str", 50);
        set("cor", 50);
        set("baohu","hxsd");
        set("couple/couple_name","Ğ¡ÈËÎï");
        set("cps", 50);
        set("int", 50);
        set("dex", 200);
        set("per", 100);
        set("agi",55);
	set("no_get",1);
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);

        set("combat_exp", 1000000);
        set("score", 9000);
        set("shen", 9000);

        set("max_qi",80000);
        set("max_jing",80000);
        set("max_neili",160000);
        set("neili",160000);
        set_skill("tianluo-diwang",400);
        set_skill("yinsuo-jinling",400);
        set_skill("strike",400);
        set_skill("whip",400);
        set_skill("yangyanshu", 400);
        set_skill("yunv-xinfa", 400);    //ÓñÅ®ĞÄ·¨
        set_skill("sword", 400);
        set_skill("yunv-jian", 400);     //ÓñÅ®½£
        set_skill("quanzhen-jian",400);  //È«Õæ½£
        set_skill("dodge", 400);
        set_skill("yunv-shenfa", 400);   //ÓñÅ®Éí·¨
        set_skill("parry", 400);
        set_skill("hubo", 400);          //Ë«ÊÖ»¥²«
        set_skill("unarmed",400);
        set_skill("meinv-quan", 400);    //ÃÀÅ®È­·¨
        set_skill("literate",400);
        set_skill("qufeng",400);         //Çı·äÖ®Êõ
        set_skill("wuzhan-mei",400);
        set_skill("dodge",400);
        set_skill("spells",400);
        set_skill("magic-old",400);
        map_skill("strike", "tianluo-diwang");
        map_skill("force", "yunv-xinfa");
        map_skill("spells", "magic-old");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "tianluo-diwang");
        map_skill("parry", "yunv-jian");
        map_skill("unarmed", "meinv-quan");
        prepare_skill("strike","tianluo-diwang");
        prepare_skill("cuff","meinv-quan");
        set("chat_chance", 10);
        set("chat_msg", ({
		(: command, "emote Õ£ÁËÕ£ÑÛµÀ£ºÎÒÃÇ²î²»¶à¸ÃÉÏÂ·ÁË°É£¬ºÃÂğ£¡" :),
                (:random_chat:),
             (:random_chat:),
             (:random_chat:),
             (:random_chat:),             	             	
        }) );

	set("inquiry", ([
		"×ß" : (: ask_go :),
		"Ç×ÈÈ" :  (: ask_kiss :),
		"µÈ´ı" :  (: ask_wait :),
		"»Ø¼Ò" :  (: ask_home :),
		"×ö·¹" :  (: ask_eat :),
		"ÆÕÍ¨¹¥»÷" :  (: ask_fight :),
		"Ò»°ã¹¥»÷" :  (: ask_fight1 :),
		"È«Á¦¹¥»÷" :  (: ask_fight2 :),
		"Ç£ÖÆ¹¥»÷" :  (: ask_fight3 :),
	]));
	setup();
        carry_object("/clone/cloth/male-shoe")->wear();
        carry_object(sprintf("/clone/cloth/male%d-cloth", random(8) + 1))->wear();
}

int init()
{
 object ob;
ob = this_player();
::init();
       add_action("do_quit","kill");
if (userp(ob)
&& ob->query("id")==query("host_id"))
{
       add_action("do_att","att");
       add_action("do_ting","ting");
       add_action("do_hulian","hulian");
       add_action("do_sha","sha");
       add_action("do_move","mache");
       add_action("do_shape","shape");
       add_action("do_lingwu","taolun");
       add_action("do_heji","heji");
       add_action("do_lian","lianxi");
       add_action("do_order", "order");
       add_action("do_name", "set_name");
       add_action("do_long", "set_long");
       add_action("do_title", "set_title");
       add_action("do_ticks", "ticks");
}
}
void random_chat()
{
  string *e,str="";
   int i;
   object npc,*inv;
if (!environment(this_object()))
   return;
   inv=all_inventory(environment(this_object()));
if(!inv)	return;
	if(!sizeof(inv))	return;
 
   e = sort_array(EMOTE_D->query_all_emote(), 1);
   str=e[random(sizeof(e))];
   command(str+" "+inv[random(sizeof(inv))]->query("id"));
   set("answer",str);  
   return;
}

void smiling (object who)
{
  if (random(2))
    command("smile");
  else
    command("smile "+who->query("id"));
}


int ask_kiss()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

        if(me->is_busy())
{
command("say Ö÷ÈË£¬ÄãÌ«Ã¦ÁË£¬ÎÒ°ï²»ÉÏÄã£¡");
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
	   if(random(10)>7)	          
           {
	   say(query("name")+"ÂúÁ³ĞßµÃÍ¨ºì£¬´¹ÏÂÍ·À´£¬»º»ºµÄµãÁËµãÍ·¡£\n");
           command("lovelook "+ me->query("id") );
           command("cat "+ me->query("id") );
           command("kiss "+ me->query("id") );
           write(CYN"Äã¶Ô"+query("name")+CYN"Î¢Î¢Ò»Ğ¦£¬Á÷Â¶³öÎŞÏŞµÄÏ²°®Ö®Çé¡£\n"NOR);
           write(CYN" "+query("name")+CYN"ÉîÉîµÄ×¢ÊÓ×ÅÄã£¬Ë«Ä¿ÔÌº­×ÅÅ¨Å¨µÄ°®Òâ¡£\n"NOR);
           command("makelove "+ me->query("id") );
           me->start_busy(1);
           this_object()->start_busy(1);
           }		
           else 
{
	   me->start_busy(1);
           this_object()->start_busy(1);
	   say(query("name")+"°¡µÄÒ»Éù£¬Ò»ÏÂ×ÓÌø½«¿ªÈ¥£¬Ëµ£º²»ĞĞ£¬²»¿ÉÒÔ¡£\n");
	   return 1;
}
           }
//	}
//else say(query("name")+"ËµµÀ£ºÅŞ£¬ÎÒ²»¸É¡£");
return 1;
}

int ask_go()
{
  object me;
  string new_name,new_id,host_id;
   me=this_player();
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

//	   if(query("id")!="bao er")
//        {
//		 sscanf(query("id"),"%s's bao er",host_id);
		 if(query("id")==query("host_id"))
           {say(query("name")+"Õö´óÑÛ¾¦¿´ÁË¿´"+
				me->query("name")+"£¬Ëµ£ºµ±È»Ô¸ÒâÀ²£¬ÎÒ¶¼ÌıÄãµÄ¡£\n");
            return 1;
           }
	 if(me->query("id")!=query("host_id"))
           {say(query("name")+"Õö´óÑÛ¾¦¿´ÁË¿´"+
				me->query("name")+"£¬Ëµ£º²»ĞĞµÄ£¬ÎÒµÃÌıÎÒÖ÷ÈËµÄ¡£\n");
			return 1;
           }
//	 }
	   command("nod");
	   command("say Ö÷ÈË´ıÎÒ¶÷ÖØÈçÉ½£¬ÎÒÒ»¶¨»á¾¡ĞÄ¾¡Á¦µÄ·şÊÌÄã£¡");
           set_leader(me);
return 1;
}

int ask_wait()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

        if(me->is_busy())
{
command("say Ö÷ÈË£¬ÄãÌ«Ã¦ÁË£¬ÎÒ°ï²»ÉÏÄã£¡");
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
           command("inn " + me->query("id"));
           command("say ÎÒÔİÊ±ÔÚÕâÀïµÈÄã£¬Èç¹ûÓĞÊ²Ã´ÊÂ£¬¼ÇµÃÕÙ»½ÎÒÅ¶£¡");
           set_leader(0);
	   return 1;
           }
//	}
//say(query("name")+"ËµµÀ:ÄãÊÇË­£¿ÎÒÓÖ²»ÈÏÊ¶Äã£¬¾Í²»ÌıÄãµÄ£¡");
return 1;
}

int ask_home()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
	if (this_object()->is_busy())
		return notify_fail("ÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");
	if( this_object()->is_fighting() )
		return notify_fail("ÒÑ¾­ÔÚÕ½¶·ÖĞÁË£¬Ñ§Ò»µãÊµÕ½¾­Ñé°É¡£\n");

	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

        if(me->is_busy())
{
command("say Ö÷ÈË£¬ÄãÌ«Ã¦ÁË£¬ÎÒ°ï²»ÉÏÄã£¡");
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
	if (is_busy() || is_fighting()) {
		command("say ÎÒÕıÃ¦×Å£¬µÈÒ»»áÔÙ»ØÈ¥¡£");
		return 1;
	}
	   if(random(10)>3)	          
           {
	   message("vision",
		 name() + "ËµµÀ£ºÖ÷ÈËÈçÔÙÒªÎÒ·ş´ı£¬Çë·¢ÉÚÎª¾¯£¡ÎÒµÈÄã°¡£¡\n\n"
		+ name() + "ÉÁÁËÉÁ¾ÍÏûÊ§²»¼ûÁË¡£\n" , environment(),
		this_object() );
	   destruct(this_object());
           }		
           else 
	   say(query("name")+"°¡µÄÒ»Éù,ÇáÉùÏ¸ÓïµÄËµ:ÇóÇó"+me->query("name")+"Ö÷ÈË,²»Òª.ÎÒ²»Òª»Ø¼Ò\n");
	   return 1;
           }
//	}
//say(query("name")+"ËµµÀ:ÄãÊÇË­£¿ÎÒÓÖ²»ÈÏÊ¶Äã£¬¾Í²»ÌıÄãµÄ£¡");
return 1;
}

int ask_fight()
{
  object me;
  string new_name,new_id;
  me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

        if(me->is_busy())
{
command("say Ö÷ÈË£¬ÄãÌ«Ã¦ÁË£¬ÎÒ°ï²»ÉÏÄã£¡");
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say ºÃµÄ£¬ÎÒ¾¡Á¿Ğ¡ĞÄ£¬²»³ö¾øÕĞÁË£¡");
           change_combat_mode(me, 0);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" ÎÒ²»ÈÏÊ¶Äã°¡£¿");
return 1;
}

int ask_fight1()
{
  object me;
  string new_name,new_id;
  me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

        if(me->is_busy())
{
command("say Ö÷ÈË£¬ÄãÌ«Ã¦ÁË£¬ÎÒ°ï²»ÉÏÄã£¡");
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say ÏÂ´ÎÕ½¶·ÎÒÒ»¶¨Ğ¡ĞÄ³öÕĞ£¡");
           change_combat_mode(me, 1);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" ÎÒ²»ÈÏÊ¶Äã°¡£¿");
return 1;
}

int ask_fight2()
{
  object me;
  string new_name,new_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

        if(me->is_busy())
{
command("say Ö÷ÈË£¬ÄãÌ«Ã¦ÁË£¬ÎÒ°ï²»ÉÏÄã£¡");
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say ÏÂ´ÎÕ½¶·ÎÒÒ»¶¨¾¡ÎÒµÄÈ«Á¦¹¥»÷¶ÔÊÖ£¡");
           change_combat_mode(me, 2);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" ÎÒ²»ÈÏÊ¶Äã°¡£¿");
return 1;
}

int ask_fight3()
{
  object me;
  string new_name,new_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

        if(me->is_busy())
{
command("say Ö÷ÈË£¬ÄãÌ«Ã¦ÁË£¬ÎÒ°ï²»ÉÏÄã£¡");
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say ÏÂ´ÎÕ½¶·ÎÒÒ»¶¨¾¡ÎÒµÄÈ«Á¦Ç£ÖÆ¶ÔÊÖ£¡");
           change_combat_mode(me, 3);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" ÎÒ²»ÈÏÊ¶Äã°¡£¿");
return 1;
}

int ask_eat() 
{
object me;
object wo;
object *obs;
int sizeinv;
object *inv;
  string new_name,new_id,host_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

        if(me->is_busy())
{
command("say Ö÷ÈË£¬ÄãÌ«Ã¦ÁË£¬ÎÒ°ï²»ÉÏÄã£¡");
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
return 1;
}

        obs = filter_array(all_inventory(me), (: ! $1->query("equipped") :));
        if (sizeof(obs) >= 38            )
{
write( CYN "ÄãÉíÉÏµÄ¶«Î÷ÊµÔÚÊÇÌ«¶àÁË£¬Ã»·¨ÔÙÄÃ³ÔµÄ¶«Î÷ÁË¡£"+"\n" NOR);
                return notify_fail("ÄãÉíÉÏµÄ¶«Î÷ÊµÔÚÊÇÌ«¶àÁË£¬Ã»·¨ÔÙÄÃ³ÔµÄ¶«Î÷ÁË¡£\n");
}
if (inv)
{
		sizeinv=sizeof(inv);
		while (sizeinv--)
		{
       			if (inv[sizeinv]->query("guardfood"))
{
write( CYN "ÄãÉíÉÏ»¹ÓĞ³ÔµÄ¶«Î÷Ã»³ÔÍêÄØ"+"\n" NOR);
     				return notify_fail("ÄãÉíÉÏ²»»¹ÓĞ³ÔµÄÂğ£¿\n");
}    		
		}
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
me = this_player();
message_vision("$NÄÃ³öÁËÒ»Ğ©×ö·¹²ÄÁÏ£¬ÉıÆğÁË»ğ£¬ÎªÖ÷ÈË$n×öÆğ·¹À´£®£®£®\n",this_object(),me);
       write( CYN ".................."+"\n" NOR);
       write( CYN "..............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN "........."+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "."+"\n" NOR);
       write( CYN " "+query("name")+"°Ñ×öÍêµÄ·¹×°ÔÚ¼¸¸öÅÌ×ÓÀï¸øÁËÄã¡£"+"\n" NOR);
       write( CYN " "+query("name")+"´Ó»³ÖĞÄÃ³ö¼¸¸öÀäÂøÍ·£¬Õ¾ÔÚÄãÅÔ±ß³ÔÁËÆğÀ´¡£"+"\n" NOR);
me->start_busy(6);
this_object()->start_busy(6);
            set ("food",170);
            set ("water",170);
if (random(30)>25)
create_water(HIW"ÑòÄÌ"NOR, ({ "milk" }), CYN"Çà»¨Íë"NOR );
else if (random(30)>20)
create_water(GRN"ÔÆÎí²è"NOR, ({ "tea" }), MAG"×ÏÉ°²èÖÑ"NOR );
else if (random(30)>20)
create_water(GRN"±ÌÂİ´º"NOR, ({ "tea" }), MAG"×ÏÉ°Õµ"NOR );
else if (random(30)>20)
create_water(HIG"¾ıÉ½ÒøÕë"NOR, ({ "tea" }), RED"ºìÄàÕµ"NOR );
else if (random(30)>20)
create_water(HIR"ºìÃ«¼â"NOR, ({ "tea" }), CYN"ÇàÄàÕµ"NOR );
else if (random(30)>20)
create_water(GRN"ÔÆÎí²è"NOR, ({ "tea" }), MAG"×ÏÉ°²èÖÑ"NOR );
else if (random(30)>20)
create_water(HIG"Áú¾®²è"NOR, ({ "tea" }), MAG"×ÏÉ°²èÖÑ"NOR );
else if (random(30)>20)
create_water(RED"ÆÕ¶ı²è"NOR, ({ "tea" }), WHT"Ë®¾§Õµ"NOR );
else if (random(30)>20)
create_water(HIG"¾ıÉ½ÒøÕë"NOR, ({ "tea" }), RED"ºìÄàÕµ"NOR );
else 
create_water(HIW"ÏÊÄÌ"NOR, ({ "milk" }), WHT"²£Á§±­"NOR );
if (random(30)>25)
                create_wine(HIW"·Ú¾Æ"NOR, ({ "wine" }), WHT"ÑòÖ¬°×Óñ±­"NOR );
else if (random(30)>20)
                create_wine(WHT"¹ØÍâ°×¾Æ"NOR, ({ "wine" }), YEL"Ï¬½Ç±­"NOR );
else if (random(30)>20)
                create_wine(RED"ÆÏÌÑ¾Æ"NOR, ({ "wine" }), HIW"Ò¹¹â±­"NOR );
else if (random(30)>20)
                create_wine(WHT"¸ßÁ»¾Æ"NOR, ({ "wine" }), CYN"ÇàÍ­¾ô"NOR );
 else if (random(30)>20)
                create_wine(HIG"°Ù²İ¾Æ"NOR, ({ "wine" }), RED"¹ÅÌÙ±­"NOR );
else if (random(30)>20)
                 create_wine(HIR"×´Ôªºì"NOR, ({ "wine" }), WHT"¹Å´É±­"NOR );
else if (random(30)>20)
                 create_wine(GRN"Àæ»¨¾Æ"NOR, ({ "wine" }), HIG"ôä´ä±­"NOR );
else if (random(30)>20)
                 create_wine(HIW"ÓñÂ¶¾Æ"NOR, ({ "wine" }), WHT"ÁğÁ§±­"NOR );
else if (random(30)>20)
                 create_wine(RED"³ÂÄê»¨µñ"NOR, ({ "wine" }), HIW"ËÎ´É±­"NOR  );
else if (random(30)>20)
                 create_wine(WHT"ÎåÁ¸Òº"NOR, ({ "wine" }), WHT"²£Á§±­"NOR );
else if (random(30)>20)
                 create_wine(WHT"Ã×¾Æ"NOR, ({ "wine" }), HIW"ÌÂ´É±­"NOR );
else if (random(30)>20)
                 create_wine(HIR"¶Å¿µ¾Æ"NOR, ({ "wine" }), HIG"ÇàÍ­¾ô"NOR  );
else if (random(30)>20)
                 create_wine(HIW"Í¸Æ¿Ïã"NOR, ({ "wine" }), WHT"ÁğÁ§±­"NOR  );
else if (random(30)>20)
                 create_wine(WHT"Ã×¾Æ"NOR, ({ "wine" }), HIW"ÌÂ´É±­"NOR );
else if (random(30)>20)
                 create_wine(GRN"ÖñÒ¶Çà"NOR, ({ "wine" }), GRN"ôä´ä±­"NOR );
else if (random(30)>20)
                 create_wine(YEL"ÉÜĞË»Æ¾Æ"NOR, ({ "wine" }), HIY"ÏóÑÀ±­"NOR );
else if (random(30)>20)
                 create_wine(HIR"Å®¶ùºì"NOR, ({ "wine" }), MAG"×ÏÌ´±­"NOR );
else if (random(30)>20)
                 create_wine(WHT"Ã©Ì¨¾Æ"NOR, ({ "wine" }), YEL"öÌ½ğ±­"NOR );
else if (random(30)>20)
                 create_wine(RED"¹ğ»¨¾Æ"NOR, ({ "wine" }), WHT"ÁğÁ§±­"NOR );
else if (random(30)>20)
                 create_food(YEL"ÏãËÖ»¨Éú"NOR,({"peanut"}) );
else 

if (random(40)>35)
                create_food(HIR"¾ÆÔãºìÔæ"NOR,({"jujube"}) );
if (random(40)>35)
                create_food(HIW"ÄÌÓÍ¹Ï×Ó"NOR,({"melon seeds","seeds"}) );
if (random(40)>35)
                create_food(HIG"±ÌÂİ´º¾í"NOR, ({ "spring roll","roll" }) );
if (random(40)>35)
                create_food(HIC"ÏãÆ¬ÕôÓã"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIW"ÂéÀ±ÊÖËº¼¦"NOR, ({"chicken"}) );
if (random(40)>35)
                create_food(HIR"¸ÉìÔÓÈÓã"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIY"¶«±±Ë®½È"NOR, ({ "dumpling" }) );
if (random(40)>35)
                create_food(RED"ÂéÀ±»ğ¹ø"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIR"ÓÍ¼åó¦Ğ·"NOR, ({ "crab" }) );
if (random(40)>35)
                create_food(HIY"·ÛÕôÈâ"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(YEL"¼Ò³£¶¹¸¯"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(HIY"µÂÖİ°Ç¼¦"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(HIG"±ÌÂİ´º¾í"NOR, ({ "spring roll","roll" }) );
if (random(40)>35)
                create_food(HIC"ÏãÆ¬ÕôÓã"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(YEL"¿§à¬·¹"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(RED"òºÓÍÈâÆ¬"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(RED"ÑòÈâ´®"NOR, ({ "mutton" }) );
if (random(40)>35)
                create_food(HIR"ÖØÇì»ğ¹ø"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIY"±±¾©¿¾Ñ¼"NOR, ({ "duck" }) );
if (random(40)>35)
                create_food(YEL"·ÛÕôÈâ"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(HIW"ËÄÏ²¶¹¸¯"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(YEL"½Ğ»¨¼¦"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(HIW"ËÄÏ²¶¹¸¯"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(HIG"±ÌÂİ´º¾í"NOR, ({ "spring","roll" }) );
if (random(40)>35)
                create_food(HIC"ÏãÆ¬ÕôÓã"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(RED"ÑòÈâ´®"NOR, ({ "mutton" }) );
if (random(40)>35)
                create_food(HIY"»¨Ö¦·¹¾í"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(HIR"ÓãÏãÈâË¿"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(HIY"µÂÖİ°Ç¼¦"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(RED"ÂéÀ±»ğ¹ø"NOR, ({ "chrafing dish","dish" }) );
if (random(40)>35)
                create_food(HIY"±±¾©¿¾Ñ¼"NOR, ({ "duck" }) );
if (random(40)>35)
                create_food(HIW"°×Õ¶¼¦"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(YEL"·ÛÕôÈâ"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(HIR"ÖØÇì»ğ¹ø"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIR"ÂéÆÅ¶¹¸¯"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(RED"òºÓÍÈâÆ¬"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(YEL"¿§à¬·¹"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(HIW"ÂéÀ±ÊÖËº¼¦"NOR, ({"chicken"}) );
if (random(40)>35)
                create_food(HIR"¸ÉìÔÓÈÓã"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIY"¶«±±Ë®½È"NOR, ({ "dumpling" }) );              return 1;
              return 1;

           }
//	}
//say(query("name")+"ÎÒí¥Ê²Ã´ÎªÄã×ö·¹£¬ÄãÓÖ²»ÊÇÎÒÖ÷ÈË£¡£¡");
//command("kick "+ me->query("id") );
return 1;
}

int do_att(string arg)
{
  object ob; 
  string host_id;
  object me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

//  if(query("id")=="bao er")
//   {say("ÄãÎŞÈ¨Ê¹ÓÃ´ËÃüÁî¡£\n");
//    return 0;}
// sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
  return notify_fail(" "+query("name")+"Á¬Àí¶¼²»ÀíÄã£¡\n");
        if(me->is_busy())
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail(" "+query("name")+"ÉµÉµµØÍû×ÅÄã£¬²»Ã÷°×ÄãµÄÒâË¼¡£\n");
  if(!living(ob)) 
	 return notify_fail(" "+query("name")+"Ëµ:"
              +ob->query("name")+"ÒÑ¾­ÕâÑùÀ²Äã»¹Òª...£¿£¿£¡£¡\n");
// ²»ÄÜÉ±×Ô¼º
	if (userp(ob) && ob == me->query("possessed"))
		return notify_fail("Äã·èÁË£¬Ïë×ÔÉ±Ã´£¿\n");
// ²»ÄÜ pk exp < ×Ô¼ºµÄÍæ¼Ò (by xbd)
	if (userp(ob) && ob->query("combat_exp") < me->query("combat_exp"))
		return notify_fail("Äã²»ÄÜÆÛ¸º±È×Ô¼ºÈõĞ¡µÄÍæ¼Ò£¡\n");
        if (userp(ob)
         && ob->query_temp("nokill") )
        return notify_fail("ÄÇÈËÆôÓÃÁËÃâÕ½ÅÆ£¡\n");

        if (userp(ob)
         && me->query_temp("nokill") )
        return notify_fail("ÄãÆôÓÃÁËÃâÕ½ÅÆ£¡\n");

    if(userp(ob) && ob->query_condition("nokill")
    && !ob->query_condition("killer"))
        return notify_fail("ÄÇ¸öÈË¸Õ±»É±¹ı£¬·Å¹ıËû°É£¡\n");	
  message_vision(name()+"¶Ô$NµãÍ·µÀ: àÅ£¬ºÃµÄ¡£\n",this_player());
command("hit "+ob->query("id"));
//  fight_ob(ob);
  return 1;
}

int do_ting()
{
   string host_id;
  object me=this_player();
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

//  if(query("id")=="bao er")
//   return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃ´ËÃüÁî¡£\n");
//  sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
   return notify_fail(" "+query("name")+"Á¬Àí¶¼²»ÀíÄã£¡\n");
 if(!is_fighting())
	 return notify_fail(" "+query("name")+"ÏÖÔÚÃ»ºÍÈË´ò¶·¡£\n");
 message_vision(" "+query("name")+"¶ÔÖ÷ÈË$NÎ¢Î¢Ò»Ğ¦£¬Ìø³öÁËÕ½È¦¡£\n",me);
command("halt");
return 1;
}

int do_send(string arg)
{
  object ob; string host_id,new_name,new_id;
  object me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

//  if(query("id")=="bao er")
//   return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃ´ËÃüÁî¡£\n");
//  sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
   return notify_fail(" "+query("name")+"Á¬Àí¶¼²»ÀíÄã£¡\n");
        if(me->is_busy())
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("ÄãÒª°Ñ "+query("name")+"ËÍ¸øË­£¿\n");
  if(!living(ob)) 
	 return notify_fail("ÄãÖ»ÄÜ°Ñ"+query("name")+"¸ø»îÈË!\n");
 message_vision(" "+query("name")+"ÑÛÀáÍôÍôµØÍû×ÅÖ÷ÈË$N£¬Ëµ:\nÖ÷ÈË´ıÎÒºÃ,ÊÇÎÒÃüºÃ;Ö÷ÈË´ıÎÒ²»ºÃ,ÊÇÎÒÃü¿à°ÕÁË.\n",me);
 set_leader(ob);
 new_name = ob->query("name")+"µÄÑ¾»·"+query("name")+" ";
	   set("long","ÕâÊÇ"+new_name+"¡£\n"
		"ËûÊÇÒ»¸öÇå´¿¾øË×µÄÉÙÅ®,´óÔ¼Ê®°Ë,¾ÅËêÄê¼Í;\n"
	            "Ëû³¤µÃ¼«ÃÀ£¬ÓÈÆäÊÇÄÇË«ÑÛ¾¦£¬Çå´¿µÃÏñÒ»Ì¶±ÌË®¡£\n"+
	            "ÆäÈİÉ«¾§Ó¨ÈçÓñ£¬Ó³ÕÕÓÚºìºìÖò¹âÖ®ÏÂ£¬½¿ÃÀ²»¿É·½Îï¡£\n"+
		"Ò»ÕÅÑ©°×µÄÁ³ÅÓ,Ã¼Íä×ìĞ¡,È´ÏóÊÇ¸ÕÊÜÈËÆÛ¸º,ÑÛÀáÍôÍôµØ¿´×ÅÄã¡£\n");
 new_id=ob->query("id")+"'s bao erÇ";
           set("possessed",ob);
           set("host_id",ob->query("id"));
 set("name",new_name);
 set("id",new_id);
 write( HIY " "+query("name")+HIY"¶ÔĞÂÖ÷ÈË"+ob->query("name")+"³ş³ş¿ÉÁ¯µØÓ¯Ó¯Ò»°İ¡£\n" NOR);
write( "¿ÉÓÃÖ¸Áî:\natt sb ¹¥»÷Ä³ÈË.\nsha sb É±ËÀÄ³ÈË.\nting Í£Ö¹Õ½¶·.
sendto sb.--°Ñ"+query("name")+"ËÍ¸øsb.
hulian skill »¥Á·Ä³Îä¹¦.
taolun skill ÌÖÂÛÄ³Îä¹¦.
mache  splace½ĞÂí³µÈ¥Ä³µØ.
heji   sb    ºÏ»÷Ä³ÈË.
shape  id    ¿´×´Ì¬.\n");

 return 1;
}

int do_sha(string arg)
{
        int i ;
	object me,ob;
	object* obj;
	me = this_object();
if (this_object()->is_busy())
return notify_fail("ËûÕıÃ¦×ÅÄØ£¡\n");
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

        if(this_player()->is_busy())
        return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É¡£\n");
if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

        if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("ÄãÒª"+query("name")+"É±Ë­£¿\n");
	if(!environment(ob)->query("no_fight"))
	{
// ²»ÄÜÉ±×Ô¼º
	if (userp(ob) && ob == me->query("possessed"))
		return notify_fail("Äã·èÁË£¬Ïë×ÔÉ±Ã´£¿\n");
// ²»ÄÜ pk exp < ×Ô¼ºµÄÍæ¼Ò (by xbd)
	if (userp(ob) && ob->query("combat_exp") < me->query("combat_exp"))
		return notify_fail("Äã²»ÄÜÆÛ¸º±È×Ô¼ºÈõĞ¡µÄÍæ¼Ò£¡\n");
        if (userp(ob)
         && ob->query_temp("nokill") )
        return notify_fail("ÄÇÈËÆôÓÃÁËÃâÕ½ÅÆ£¡\n");

        if (userp(ob)
         && me->query_temp("nokill") )
        return notify_fail("ÄãÆôÓÃÁËÃâÕ½ÅÆ£¡\n");

    if(userp(ob) && ob->query_condition("nokill")
    && !ob->query_condition("killer"))
        return notify_fail("ÄÇ¸öÈË¸Õ±»É±¹ı£¬·Å¹ıËû°É£¡\n");	
        message_vision(name()+"¶Ô$NµãÍ·ËµµÀ: àÅ£¬ºÃµÄ¡£\n",this_player());
	command("say ºß£¬Ö÷ÈËÒªÎÒÉ±ÁËÄã£¡");
        command("hit " + ob->query("id"));
	}
	return 1;
}       

void kill_ob(object ob)
{
if (ob->query("id")==query("host_id"))
{
command("say ÎÒ¶ÔÖ÷ÈË¾¡ĞÄ¾¡Á¦,µ«Ö÷ÈËÄãÎªÊ²Ã´ÒªÉ±ÎÒ°¡£¡");	
command("die");
call_out("destroying", 0,ob);   
   return;      
}
}

int do_quit(string arg)
{
        object ob= this_object();
	object me= this_player();
	if(arg==query("host_id")
	&& me->query("id")!=arg) {
        command("say " + me->name() + "£¬ÄãÏë×öÊ²Ã´£¡²»ÒªÉËÎÒÖ÷ÈË£¡");
        command("emote ÉÁÉíµ²ÔÚÄãµÄÃæÇ°£¡");
//        me->fight_ob(ob);
        ob->fight_ob(me);
        return 1;
	}
}
int do_hulian(string arg)
{
 	object me=this_player();
 	object where = environment(me);
	string skillname;
	int skill, skill_basic, times, pertimes;

	seteuid(getuid());
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (me->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
if (this_object()->is_busy())
return notify_fail("ËûÕıÃ¦×ÅÄØ£¡\n");

        if (where->query("pigging"))
                return notify_fail("Äã»¹ÊÇ×¨ĞÄ¹°Öí°É£¡\n");
        if (me->is_busy())
                return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

	if( (int)me->query("qi") < 50 )
		return notify_fail("ÄãÃ»ÓĞÄÇÃ´¶àµÄÆø£¡\n");

	if( (int)me->query("jing") < 50 )
		return notify_fail("ÄãÏÖÔÚ¾«²»¹»£¡\n");

        if (where->query("sleep_room"))
                return notify_fail("ÎÔÊÒ²»ÄÜ»¥Á·£¬»áÓ°Ïì±ğÈËĞİÏ¢¡£\n");
if( environment(me)->query("outdoors") ) 
          return notify_fail(HIY"\n²»ÒªÓ°Ïì±ğÈË£¬»¹ÊÇÕÒÒ»¸öÊÒÄÚµÄµØ·½°É¡£\n"NOR);

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n²»ÒªÓ°Ïì±ğÈË£¬»¹ÊÇÕÒÒ»¸ö±ğµÄµØ·½°É¡£\n"NOR);

	if( me->is_fighting() )
		return notify_fail("ÄãÒÑ¾­ÔÚÕ½¶·ÖĞÁË£¬Ñ§Ò»µãÊµÕ½¾­Ñé°É¡£\n");

	if( !arg ) 
		return notify_fail("ÄãÒª»¥Á·Ê²Ã´Îä¹¦°¡¡£\n");


	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("Ö¸Áî¸ñÊ½£ºpractice|lian <¼¼ÄÜÖÖÀà> <´ÎÊı>\n");

	if ( times < 1 || times > 10)
		return notify_fail("»¥Á·´ÎÊı±ØĞë´óÓÚÒ»´Î£¬µ«²»ÄÜ³¬¹ıÊ®´Î¡£\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("ÄãÖ»ÄÜÁ·Ï°ÓÃ enable Ö¸¶¨µÄÌØÊâ¼¼ÄÜ¡£\n");


	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("ÄãºÃÏñ»¹Ã»ÓĞÑ§¹ıÕâÏî¼¼ÄÜ°É£¿×îºÃÏÈÈ¥Çë½Ì±ğÈË¡£\n");
	if( skill_basic < 1 )
		return notify_fail("Äã¶ÔÕâ·½ÃæµÄ¼¼ÄÜ»¹ÊÇÒ»ÇÏ²»Í¨£¬×îºÃ´ÓÏÈ´Ó»ù±¾Ñ§Æğ¡£\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("ÄãµÄ»ù±¾¹¦»ğºòÎ´µ½£¬±ØĞëÏÈ´òºÃ»ù´¡²ÅÄÜ¼ÌĞøÌá¸ß¡£\n");

	notify_fail("ÄãÏÖÔÚ²»ÄÜÁ·Ï°ÕâÏî¼¼ÄÜ¡£\n");

	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
		return notify_fail("Ò²ĞíÊÇÈ±·¦ÊµÕ½¾­Ñé£¬ÄãµÄÁ·Ï°×ÜÃ»·¨½ø²½¡£\n");

	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("ÄãÊÔ×ÅÁ·Ï°" + to_chinese(skillname) + "£¬µ«ÊÇ²¢Ã»ÓĞÈÎºÎ½ø²½¡£\n");

	write( HIW "ÄãÓë"+query("name")+"°Ñ" + to_chinese(skillname) + HIW"»¥Á·ÁË"+chinese_number(times)+"ÌË¡£\n" NOR);
	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
	{
                me->start_busy(1);
		return notify_fail("Ò²ĞíÊÇÈ±·¦ÊµÕ½¾­Ñé£¬ÄãµÄÁ·Ï°×ÜÃ»·¨½ø²½¡£\n");
		return 1;
	}

	for (pertimes = 1; pertimes <= times; pertimes ++)
	{
		if( SKILL_D(skillname)->practice_skill(me) )
{
			me->improve_skill(skillname, (skill_basic/5 +1), skill_basic > skill? 0: 1);
			me->improve_skill(skillname, (skill_basic/5 +1), skill_basic > skill? 0: 1);
}
		else return 0;
	}
	write( HIY "ÄãµÄ" + to_chinese(skillname) + "½ø²½ÁË£¡\n" NOR);
	return 1;
}

void destroying(object ob)
{   
object me=this_player();
command("say Ö÷ÈËÄãÒªÉ±ÎÒ£¬²»ÀÍÄú¶¯ÊÖ¡£¡£¡£\n");
command("say ÎÒµÄÃüÕæ¿à¡£¡£¡£\n");
command("say "+me->query("name")+"Ö÷ÈËÒÔºóÎÒ²»ÄÜ¼ÌĞøÔÙ·ş´ıÄãÁË¡£¡£¡£\n");
command("say ´ó¼ÒÕäÖØ¡£¡£¡£\n");
command("say ÕäÖØ¡£¡£¡£\n");
message_vision("$NËµ°Õ£¬ÄÃÆğ½£×ÔØØ¶øËÀ£¬Ëû»º»ºµÄµ½ÔÚµØÉÏ¡£¡£¡£\n",this_object());
this_object()->die();
   return;      
}

int do_move(string arg)
{

          string pla;
          object me = this_player();
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");
if (this_object()->is_busy())
return notify_fail("ËûÕıÃ¦×ÅÄØ£¡\n");
if (this_player()->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

if( me->query("jing") < 50 )
               return notify_fail("ÄãÉíÌå²»Ì«ºÃ£¬×öÂí³µ¼Ó³öÊÂµÄ£¡\n");
if( me->is_busy())
return notify_fail("ÄãÏÖÔÚÔÚÕıÃ¦×ÅÄØ£¡\n");

if( !environment(me)->query("no_fight"))
{
  message_vision("Ö»ÓĞÔÚ°²È«µÄµØ·½²ÅÄÜ½ĞÂí³µ£¡\n"
                 ,me);
      	return 1;
}
if (!arg)
return notify_fail("ÄãÏëÈ¥ÄÄÀïÄØ£¿\n");
if( !wizardp(me) && me->is_fighting()  ) 
 return notify_fail("ÄãÔÚºÍ±ğÈË´ò¼Ü£¬Ã»¿Õ½ĞÂí³µ°É£¿\n");
          else {
}
          if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="xx") pla = "/d/xingxiu/xxh1";
     else if(arg=="mj") pla = "/d/mingjiao/shanmen";
     else if(arg=="em") pla = "/d/emei/qingyinge";
     else if(arg=="shl") pla = "/d/shaolin/guangchang1";
     else if(arg=="lj") pla = "/d/lingjiu/damen";
     else if(arg=="dl") pla = "/d/dali/center";
     else if(arg=="xs") pla = "/d/xueshan/shanmen";
     else if(arg=="wd") pla = "/d/wudang/guangchang";
     else if(arg=="hs") pla = "/d/huashan/zhenyue";
     else if(arg=="tam") pla = "/d/beijing/tian_anm";
     else if(arg=="quz") pla = "/d/quanzhen/damen";
     else if(arg=="bt") pla = "/d/baituo/dating";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="sz") pla = "/d/suzhou/canlangting";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";

               else {
command("snake");
               message_vision(HIW
"Âí³µ²»µ½ÄÇ¸öµØ·½°¡£¡\n"NOR, me);
               message_vision(HIY
"³µĞĞÀï¿ÉÒÔÈ¥µÄµØ·½ÓĞÈçÏÂ£º
Ìì°²ÃÅ(tam) ´óÀí(dl) ÈªÖİ(qz) ÉÙÁÖ(shl)»ªÉ½(hs) ÁéğÕ(lj)  
Îäµ±(wd)    Ã÷½Ì(mj) ÑïÖİ(gc) ĞÇËŞ(xx) Ñ©É½(xs) ¶ëÃ¼(em)  
È«Õæ(quz)  °×ÍÕÉ½(bt) ¹ÅÄ¹(gm) ËÕÖİ(sz)¹éÔÆ×¯(gyz)ÏåÑô(xy)  \n"NOR, me);

}
     if (me->move(pla)) {
          message_vision(HIG
"$N¶Ô"+query("name")+HIG"Ëµ£ºÕâ¸½½üÓĞÃ»ÓĞÂí³µ£¬ÎÒÃÇÒª¸ÏÂ·ÁË\n"+
query("name")+HIG"ÔÚ¸½½ü½ĞÁËÒ»Æ¥Âí³µ£¬\n$NºÍ"+query("name")+HIG"Ë«Ë«ÉÏÂí£¬ÏòÍâ·ÉÅÜ¶øÈ¥¡£¡£¡£\n\n"NOR, me);
       message_vision(HIC"\nÒ»Â·±¼³Û£¬ÖÕÓÚµ½ÁË£¡ÄãºÍ"+query("name")+HIC"Ë«Ë«·ÉÉíÒ»Ô¾£¬ÌøÏÂÂí³µ¡£\n"NOR,me);
this_object()->move(pla);
me->add("jing",-30);
me->start_busy(4);
}
     return 1;
}

string status_color(int current, int max)
{
        int percent;


        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
int do_shape(string arg)
{	mapping my;
	string shape;
	int at_pt,pa_pt,do_pt;
if (!arg)
return notify_fail("ÄãÒª¿´Ë­µÄ×´Ì¬£¿\n");
if (arg !=query("id"))
return notify_fail("ÄãÒª¿´Ë­µÄ×´Ì¬£¿\n");
	my = query_entire_dbase();
	 printf(HIC"¡Ô"HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIC"¡Ô\n"NOR);
printf(HIC"¾«Á¦£º"NOR"%s%3d/ %3d %s(%3d%%)   "HIC"ÆøÑª£º"NOR"%s%3d/ %3d %s(%3d%%)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]            
	);		
	printf(HIW"Ö÷ÈË£º "HIG"%s"NOR"\t\t"HIW"¾­Ñé£º "HIG"%d"NOR"\t\t"HIW"É±Æø£º "HIG"%d"NOR"\n"NOR,
	my["host_id"], my["combat_exp"],my["bellicosity"]
	);
        printf(HIY"ÎòĞÔ£º "HIG"%d"NOR"\t\t"HIY"¸ù¹Ç£º "HIG"%d"NOR"\t\t"HIY"ÈİÃ²£º "HIG"%d"NOR"\n"NOR,
        query_int(), query_con(),query_per()
        );
        printf(HIY"Éí·¨£º "HIG"%d"NOR"\t\t"HIY"±ÛÁ¦£º "HIG"%d"NOR"\t\t"HIY"¸£Ôµ£º "HIG"%d"NOR"\n"NOR,
        query_dex(), query_str(),query_kar()
        );
        printf(HIY"ÄÚÁ¦£º "HIG"%d"NOR"\t\t"HIY"ÄÚÁ¦ÉÏÏŞ£º "HIG"%d"NOR"\t\t\n"NOR,
        query("neili"), query("max_neili")
        );

        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf(HIR"¹¥»÷Á¦£º %d\t"NOR+HIR"·ÀÓùÁ¦£º %d\t\n"NOR,
        at_pt+1, pa_pt/2+do_pt/2+1
        );
	printf("/cmds/skill/skills"->pet_skill(this_object()));
	 printf(HIC"¡Ô"HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIC"¡Ô\n"NOR);return 1;
}


// ÓÀ¾Ã¸úËæÖ÷ÈË (by xbd)
int chat()
{
	object me = query("possessed");
	int i, ratio, chance, rnd, flag = 0;
	string *msg, *emotes, cmd;
	object *inv, *killer;

	if (!me) {
		if( environment() && !is_fighting() )
			call_out("leave", 0);
		return 0;
	}

if( !environment(me) ) return 0;
	if( !environment() ) return 0;
	if( query_temp("is_unconcious") ) return 0;

	if (environment(this_object()) != environment(me)
	&& !is_fighting()
	&& !is_busy()
	&& query_leader() == me) {
		command("say Ö÷ÈËµÈµÈÎÒ£¡£¡£¡");
		move(environment(me));
		command("say Ö÷ÈË£¬±ğ×ßÄÇÃ´¿ì£¬ÎÒ²îµã¸ú²»ÉÏÁË£¡");
	}

	if (!is_busy()) {
		if (arrayp(msg = get_auto_actions("powerup")))
			for (i = 0; i < sizeof(msg); i++)
				if (functionp(msg[i]))
					evaluate(msg[i]);
	}

	if (living(me)
	&& !me->is_ghost()
	&& me->is_killing()
	&& me->is_fighting()
	&& !is_fighting()
	&& !is_killing()
	&& !is_busy()
	&& intp(ratio = (int)me->query("env/save_me"))
	&& ratio > 0
	&& ( me->query("qi") * 100 / me->query("max_qi") <= ratio
		|| me->query("jing") * 100 / me->query("max_jing") <= ratio))
	{
		if (environment(this_object()) != environment(me)) {
			command("say ²»ºÃ£¬Ö÷ÈËÓĞÎ£ÏÕ£¡£¡£¡");
			move(environment(me));
		}
		command("say Ö÷ÈËÓĞÄÑ£¬ÎÒÒ»¶¨»áÊÄËÀ±£»¤ÄãµÄ£¡£¡£¡");
		if (arrayp(killer = me->query_enemy()))
			for (i = 0; i < sizeof(killer); i++)
				if (objectp(killer[i])) {
					this_object()->fight_ob(killer[i]);
					killer[i]->fight_ob(this_object());
					this_object()->fight_ob(killer[i]);
					killer[i]->fight_ob(this_object());
				}
	}

	if (query("neili") > 100 && query("max_neili") > 200 && !is_busy()) {
		if (query("eff_jing") && query("jing") * 100 / query("eff_jing") <= 80)
			command("exert regenerate");

		if (query("eff_qi") && query("qi") >= 0 && query("qi") * 100 / query("eff_qi") <= 80)
			command("exert recover");

		if (query("eff_qi") && query("qi") >= 0
		&& query("max_qi") && !is_fighting() && !query("mute")
		&& query_skill_mapped("force")
		&& query("eff_qi") < query("max_qi")
		&& query("eff_qi") >= query("max_qi") / 3)
			command("exert heal");

		if (query("max_neili")
		&& query("neili") * 100 / query("max_neili") <= 80
		&& !is_fighting()
		&& query_skill_mapped("force")) {
			i = 1 + (int)query_skill("force") / 15 * (1 + (int)query_skill("force") / 100);
			command(sprintf("dazuo %d", i));
		}

	}

	if (is_fighting()) {
		for (i = 1; i <= 5; i++)
			if (stringp(cmd = query(sprintf("ticks/%d", i))))
			{
				command(cmd);
				flag = 1;
			}
		if (flag) return 1;
	}

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( query_temp("is_unconcious") ) return 0;
		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}

	return 1;
}

void leave()
{
        if(!objectp(query("possessed")))
	{
	set_heart_beat(1);	
	command("say  Ö÷ÈË²»ÔÚ£¬ÎÒ»Ø¼ÒËãÁË¡£");
	command("emote ÍùÈËÈºÀïÒ»ÉÁ¾Í²»¼ûÁË¡£");
        destruct(this_object());
	}
	set_heart_beat(1);
}

int do_lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;
        string msg;
	if( !living(this_object()) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + this_object()->name() + "ÅªĞÑÔÙËµ¡£\n");

if (me->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
if (this_object()->is_busy())
return notify_fail("ËûÕıÃ¦×ÅÄØ£¡\n");

        if (environment(me)->query("pigging"))
                return notify_fail("Äã»¹ÊÇ×¨ĞÄ¹°Öí°É£¡\n");
        if (me->is_busy())
                return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

	if( (int)me->query("qi") < 50 )
		return notify_fail("ÄãÃ»ÓĞÄÇÃ´¶àµÄÆø£¡\n");

	if( (int)me->query("jing") < 50 )
		return notify_fail("ÄãÏÖÔÚ¾«²»¹»£¡\n");
if( environment(me)->query("outdoors") ) 
          return notify_fail(HIY"\n²»ÒªÓ°Ïì±ğÈË£¬»¹ÊÇÕÒÒ»¸öÊÒÄÚµÄµØ·½°É¡£\n"NOR);

        if (environment(me)->query("sleep_room"))
                return notify_fail("ÎÔÊÒ²»ÄÜÌÖÂÛ£¬»áÓ°Ïì±ğÈËĞİÏ¢¡£\n");

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n²»ÒªÓ°Ïì±ğÈË£¬»¹ÊÇÕÒÒ»¸ö±ğµÄµØ·½°É¡£\n"NOR);

	if( me->is_fighting() )
		return notify_fail("ÄãÒÑ¾­ÔÚÕ½¶·ÖĞÁË£¬Ñ§Ò»µãÊµÕ½¾­Ñé°É¡£\n");

	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("ÄãÕıÃ¦×ÅÄØ¡£\n");

	if (me->query("potential") - me->query("learned_points") < 0) 
         return notify_fail("ÄãµÄÇ±ÄÜÌ«ÉÙÁË£¡\n");	

	if (!arg) return notify_fail("ÄãÒªÓë"+query("name")+"ÌÖÂÛÊ²Ã´£¿\n");
	if (!me->query_skill(arg,1))
		return notify_fail("Äã²»»áÕâÖÖ¼¼ÄÜ¡£\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("Õâ¸öÎä¹¦ºÃÏñ´ÓÌØÊâ¼¼ÄÜÖĞÁìÎò¡£\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 20) {
		me->receive_damage("jing",bl/2);
		return notify_fail("ÄãÃ»°ì·¨¼¯ÖĞ¾«Éñ¡£\n");
	}
	if(me->query("potential") < 100 ) 
         return notify_fail("ÄãµÄÇ±ÄÜÌ«ÉÙÁË£¡\n");	

	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("ÄãµÄ"+to_chinese(special)+"ÔìÒè²»¹»£¬ÎŞ·¨¶Ô¸üÉîÒ»²ãµÄ"+CHINESE_D->chinese(arg)+"½øĞĞÌÖÂÛ¡£\n");
	write(HIY"ÄãºÍ"+query("name")+HIY"Ï¯µØ¶ø×ø£¬¿ªÊ¼¶Ô"+to_chinese(arg)+HIY"µÄÊ¹ÓÃ·½·¨ºÍÌå»á½øĞĞºÍÌÖÂÛ¡£\n"NOR);
	me->receive_damage("jing",bl/2);
	me->improve_skill(arg,sl/5+2);
	write(HIG"ÔÚ"+query("name")+HIG"µÄ°ïÖúºÍÄãµÄÅ¬Á¦ÏÂ¡£\nÄã¶Ô"+to_chinese(arg)+HIG"ºÃÏñÓĞÁË¸üÉîÒ»²ãµÄÁË½â£¡\n"NOR);
	return 1;
}
int do_heji(object me, string arg)
{
        int same_place;
        string couple_id;
        string couple_name;
        object couple;
        object target;
object weapon,weapon1;
 int extra,extra1;
 string msg;
me=this_player();
weapon = me->query_temp("weapon");
weapon1 = this_object()->query_temp("weapon");
if (!weapon) 
return notify_fail("ÄãÃ»ÓĞÎäÆ÷£¡\n");
if (!weapon1) 
return notify_fail("ËûÃ»ÓĞÎäÆ÷£¡\n");

if (me->query("id")!=query("host_id"))
return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
if (this_object()->is_busy())
return notify_fail("ËûÕıÃ¦×ÅÄØ£¡\n");
        if (me->is_busy())
                return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");
        if (this_object()->is_busy())
                return notify_fail("ËûÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

        if (environment(me)->query("no_fight"))
                return notify_fail("ÕâÀï²»ÄÜÕ½¶·¡£\n");

        if (! arg)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        } else
                target = present(arg, environment(me));

        if (! target || ! me->is_fighting(target))
                return notify_fail("ºÏ»÷Ö»ÄÜ¶ÔÁ½ÈË¶¼ÔÚÕ½¶·ÖĞµÄ¶ÔÊÖÊ¹ÓÃ¡£\n");

        if (! target || ! this_object()->is_fighting(target))
                return notify_fail("ºÏ»÷Ö»ÄÜ¶ÔÁ½ÈË¶¼ÔÚÕ½¶·ÖĞµÄ¶ÔÊÖÊ¹ÓÃ¡£\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ä¿Ç°Õı×Ô¹Ë²»Ï¾£¬·Åµ¨¹¥»÷°É!\n");

        message_combatd(HIY " $N" HIY "ºÍ$n" HIY "Á½ÈËÑÛÉñÒ»½»£¬ĞÄÒâÒÑ"
                        "È»ÏàÍ¨£¬²»ÓÉµÄ»áĞÄÒ»Ğ¦£¬Ö»¼û¶şÈËÉíĞÎÒ»´í£¬ö®Ê±\n"
                        " ÒÑ¾­Ïò" + target->name() + "¹¥³öÊıÕĞ£¡\n" NOR,
                        me, this_object());
if (random(this_object()->query("combat_exp")) >target->query("combat_exp")/3)
{
                        msg = HIG " "+query("name")+ HIG "µ¯" + weapon1->name() +
                              HIG"ÇáÒ÷£¬ÍğÈô»Æİº³ö¹È£¬Æ®Éí¶ø½ø£¬ÊÖÖĞµÄ" +
                              weapon1->name() + HIG "»¯×÷Á÷ĞÇÒ¹Óê£¬ÅûÏò"+target->query("name")+" "
                              HIG "¡£\n" NOR;
target->start_busy(4);
msg += HIR " ½á¹û"+target->query("name")+HIR"±»"+query("name")+HIR"ÄÖ¸öÊÖÃ¦½ÅÂÒ£¬¾ª»ÅÊ§´ë£¬´ôÔÚµ±³¡£¬²»ÖªÈçºÎÓ¦¶Ô£¡\n" NOR;
message_combatd(msg, me, target);
          message_combatd(HIW" " + me->name() + HIW"¼û" + query("name") + HIW"µÃÊÖ£¬¼±ÏòÇ°Ô¾£¬²¹×ãÁË" + query("name") + HIW"µÄÆÆÕÀ£¬²¢Á¬Á¬³öÕĞ£¡\n" NOR,
                        me, this_object());
                        msg = HIC " " + me->name() + HIC"×İÉù³¤Ğ¥£¬Ò»¹ÉÉ±ÆøÁİÈ»¶øÆğ£¬Ìì"
                              "µØµÇÊ±É«±ä£¬$N" HIC "Ğ®·çÀ×Íò¾ûÖ®ÊÆ£¬Ñ¹Ïò"+target->query("name")+HIC"
                              ¡£\n" NOR;
extra=(int)me->query_skill("force",1)/10;
extra1=(int)this_object()->query_skill("force",1)/10;	
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	this_object()->add_temp("apply/attack", extra1);
	this_object()->add_temp("apply/damage", extra1);

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC " " + query("name") + HIC"½ô¸ú×Å£¬´Ó×óÃæÓÖÊÇÒ»»÷£¡\n" NOR;
	COMBAT_D->do_attack(this_object(),target, weapon1, TYPE_REGULAR,msg);
msg = HIW " " + me->query("name") + HIW"½ô¸ú×Å£¬´ÓÓÒÃæÓÖÊÇÒ»»÷£¡\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC " " + query("name") + HIC"×îºó£¬´ÓÉÏÃæ²¹×ãÒ»»÷£¡\n" NOR;
	COMBAT_D->do_attack(this_object(),target, weapon1, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	this_object()->add_temp("apply/attack", -extra1);
	this_object()->add_temp("apply/damage", -extra1);

me->add("neili",200);
this_object()->add("neili",200);
me->start_busy(1);
this_object()->start_busy(1);
}
else
{
          message_combatd(" " + target->name() + "¼±ÏòºóÔ¾£¬Ìø³öÁË±»ºÏ»÷µÄ·¶Î§£¡\n" NOR,
                        me, this_object());
me->add("neili",200);
this_object()->add("neili",200);
me->start_busy(2);
this_object()->start_busy(2);
}
        return 1;
}

int do_lian(string arg)
{
 	object me = this_player(), ob = this_object();
 	object where = environment(me);
	string skillname;
	int skill, skill_basic, times, pertimes;
	int neili, jing, qi;

	seteuid(getuid());

	if (me->query("id") != query("host_id"))
		return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");

	if( !arg ) 
		return notify_fail("ÄãÏëÈÃËûÁ·Ï°Ê²Ã´Îä¹¦£¿\n");

	if ((sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("Ö¸Áî¸ñÊ½£ºlianxi <¼¼ÄÜÖÖÀà> <´ÎÊı>\n");

	if( !living(ob) )
		return notify_fail("àÅ....ÄãµÃÏÈ°Ñ" + ob->name() + "ÅªĞÑÔÙËµ¡£\n");

        if (where->query("pigging"))
                return notify_fail("Äã»¹ÊÇ×¨ĞÄ¹°Öí°É£¡\n");
        if (where->query("sleep_room"))
                return notify_fail("ÎÔÊÒ²»ÄÜ»¥Á·£¬»áÓ°Ïì±ğÈËĞİÏ¢¡£\n");
	if( environment(me)->query("no_beg") &&	environment(me)->query("no_fight") && environment(me)->query("no_steal")) 
		return notify_fail(HIY"\n²»ÒªÓ°Ïì±ğÈË£¬»¹ÊÇÕÒÒ»¸ö±ğµÄµØ·½°É¡£\n"NOR);

        if (me->is_busy())
                return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");
	if( me->is_fighting() )
		return notify_fail("ÄãÒÑ¾­ÔÚÕ½¶·ÖĞÁË£¬Ñ§Ò»µãÊµÕ½¾­Ñé°É¡£\n");
	if (ob->is_busy())
		return notify_fail("ËûÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");
	if( ob->is_fighting() )
		return notify_fail("ËûÒÑ¾­ÔÚÕ½¶·ÖĞÁË£¬Ñ§Ò»µãÊµÕ½¾­Ñé°É¡£\n");

	if ( times < 1 || times > 30)
		return notify_fail("»¥Á·´ÎÊı±ØĞë´óÓÚÒ»´Î£¬µ«²»ÄÜ³¬¹ıÈıÊ®´Î¡£\n");
	if( !stringp(skillname = ob->query_skill_mapped(arg)) )
		return notify_fail("ÄãÖ»ÄÜÁ·Ï°ÓÃ enable Ö¸¶¨µÄÌØÊâ¼¼ÄÜ¡£\n");

	skill_basic = ob->query_skill(arg, 1);
	skill = ob->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("ËûºÃÏñ»¹Ã»ÓĞÑ§¹ıÕâÏî¼¼ÄÜ°É£¿\n");
	if( skill_basic < 1 )
		return notify_fail("Ëû¶ÔÕâ·½ÃæµÄ¼¼ÄÜ»¹ÊÇÒ»ÇÏ²»Í¨£¬×îºÃ´ÓÏÈ´Ó»ù±¾Ñ§Æğ¡£\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("ËûµÄ»ù±¾¹¦»ğºòÎ´µ½£¬±ØĞëÏÈ´òºÃ»ù´¡²ÅÄÜ¼ÌĞøÌá¸ß¡£\n");

	notify_fail("ËûÏÖÔÚ²»ÄÜÁ·Ï°ÕâÏî¼¼ÄÜ¡£\n");

	if (skill*skill*skill/10 > (int)ob->query("combat_exp")) 
		return notify_fail("Ò²ĞíÊÇÈ±·¦ÊµÕ½¾­Ñé£¬ËûµÄÁ·Ï°×ÜÃ»·¨½ø²½¡£\n");

//	if( !SKILL_D(skillname)->valid_learn(ob) ) return 0;

	notify_fail("ËûÊÔ×ÅÁ·Ï°" + to_chinese(skillname) + "£¬µ«ÊÇ²¢Ã»ÓĞÈÎºÎ½ø²½¡£\n");

	write( HIW "ÔÚÄãµÄÖ¸µ¼ÏÂ£¬" + ob->name() + "°Ñ" + to_chinese(skillname) + HIW"Á·Ï°ÁË"+chinese_number(times)+"ÌË¡£\n" NOR);
	if (skill*skill*skill/10 > (int)ob->query("combat_exp")) 
	{
                me->start_busy(1);
		return notify_fail("Ò²ĞíÊÇÈ±·¦ÊµÕ½¾­Ñé£¬ËûµÄÁ·Ï°×ÜÃ»·¨½ø²½¡£\n");
		return 1;
	}

	for (pertimes = 1; pertimes <= times; pertimes ++)
	{
// ÓÃ×Ô¼ºµÄjing¡¢qi¡¢neiliÀ´½øĞĞÁ·Ï°
		jing = random(200);
		qi = random(400);
		neili = random(200);
		if (me->query("jing") < jing)
			return notify_fail("ÄãµÄ¾«ÆøÌ«µÍÁË£¬ÎŞ·¨¼ÌĞøÖ¸µ¼ËûµÄÁ·Ï°£¡\n");
		if (me->query("qi") < qi)
			return notify_fail("ÄãµÄÆøÑªÌ«µÍÁË£¬ÎŞ·¨¼ÌĞøÖ¸µ¼ËûµÄÁ·Ï°£¡\n");
		if (me->query("neili") < neili)
			return notify_fail("ÄãµÄÄÚÁ¦Ì«µÍÁË£¬ÎŞ·¨¼ÌĞøÖ¸µ¼ËûµÄÁ·Ï°£¡\n");
		me->add("jing", -jing);
		me->add("qi", -qi);
		me->add("neili", -neili);
		ob->improve_skill(skillname, (skill_basic/5 +1), skill_basic > skill? 0: 1);
	}
	write( HIY + ob->name() + "µÄ" + to_chinese(skillname) + "½ø²½ÁË£¡\n" NOR);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!query("no_accept") || who == query("possessed")) {
		command("thank " + who->query("id"));
		return 1;
	}
	command("shake " + who->query("id"));
	command("say Ö÷ÈËºÍÎÒËµ¹ı£¬±ğËæ±ãÄÃ±ğÈËµÄ¶«Î÷£¡");
	return 0;
}

int accept_fight(object ob)
{
	if (!query("no_fight") || ob == query("possessed")) {
		command("say ºÃ°É£¬ÄãĞ¡ĞÄÁË£¡");
		return 1;
	}
	command("shake " + ob->query("id"));
	command("say Ö÷ÈËºÍÎÒËµ¹ı£¬²»ÒªËæ±ãºÍ±ğÈË¶¯Îä£¡");
	return 0;

}

int do_order(string arg)
{
	object me = this_player();
	string type, cmd;
	int i;
	
	seteuid(getuid());

	if (me->query("id") != query("host_id"))
		return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if( !arg ) 
		return notify_fail("ÄãÏëÈÃËû×öÊ²Ã´£¿\n");
	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		return notify_fail("Ö¸Áî¸ñÊ½£ºorder [un]accept object | [un]accept fight | <Ö¸Áî>\n");
	if (!living(this_object()))
		return notify_fail("ÒÔËûÄ¿Ç°µÄ×´Ì¬£¬ÔõÃ´¿ÉÄÜÌıÄãµÄÃüÁîÄØ£¿\n");

	if (type == "accept") {
		if (cmd == "object") {
			me->set("guard/status/no_accept", 0);
			set("no_accept", 0);
			command("nod");
			command("say ºÃµÄ£¬ÎÒÒÔºó¾Í´úÄã½ÓÊÜ±ğÈËµÄ¶«Î÷°É£¡");
			return 1;
		}
		if (cmd == "fight") {
			me->set("guard/status/no_fight", 0);
			set("no_fight", 0);
			command("nod");
			command("say ºÃµÄ£¬ÎÒÒÔºóÒ²ºÍ±ğÈËÒ»ÆğÇĞ´èÇĞ´èÎäÒÕ£¡");
			return 1;
		}
		return notify_fail("Ö¸Áî¸ñÊ½£ºorder accept object|fight\n");
	}

	if (type == "unaccept") {
		if (cmd == "object") {
			me->set("guard/status/no_accept", 1);
			set("no_accept", 1);
			command("nod");
			command("say ºÃµÄ£¬ÎÒÒÔºóÔÙÒ²²»Ëæ±ã½ÓÊÜ±ğÈËµÄ¶«Î÷ÁË£¡");
			return 1;
		}
		if (cmd == "fight") {
			me->set("guard/status/no_fight", 1);
			set("no_fight", 1);
			command("nod");
			command("say ºÃµÄ£¬ÎÒÒÔºóÔÙÒ²²»Ëæ±ãºÍ±ğÈË±ÈÎäÁË£¡");
			return 1;
		}
		return notify_fail("Ö¸Áî¸ñÊ½£ºorder unaccept object|fight\n");
	}

	for (i = 0; i < sizeof(cmds); i++)
		if (cmds[i] == type) {
			exec_cmd(me, arg);
			return 1;
		}

	return notify_fail("ÄãÖ»ÄÜ¶ÔËûÏÂ´ïÕ½¶·Ö¸Áî£¡\n");
}

void exec_cmd(object me, string arg)
{
	if (!command(arg))
		write("ËûÏÖÔÚÎŞ·¨ÕıÈ·Ö´ĞĞÄãµÄÃüÁî£¡\n");
	else
		write("×ñÃü£¬Ö÷ÈË£¡\n");
}

mixed get_auto_actions(string action)
{
	int i, flag = 0;

	for (i = 0; i < sizeof(pfm); i++)
		if (pfm[i]["party"] == query("party")) {
			flag = 1;
			break;
		}
	if (!flag)
		return ({ });
	if (arrayp(pfm[i][action]))
		return pfm[i][action];
	else
		return ({ });
}

void change_combat_mode(object me, int mode)
{
	switch (mode) {
	case 0:
		delete("chat_chance_combat");
		delete("chat_msg_combat");
		set("jiali", 1);
		break;
	case 1:
		set("chat_chance_combat", 50);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		break;
	case 2:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform1"));
		set("jiali", (int)query_skill("force") / 2);
		break;
	case 3:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform2"));
		set("jiali", 1);
		break;
	default:
		return;
	}
	set("combat_mode", mode);
	me->set("guard/status/combat_mode", mode);
}

void die()
{
	object ob = this_object();
	
	if (environment(ob)->query("pingan") || environment(ob)->query("biwu") || environment(ob)->query("citybiwu")) {
		message_vision(HIR "±ÈÎäÖ®µØ£¬Ö»·ÖÊ¤¸º£¬²»·ÖÉúËÀ¡£$N±»´ò°ÜÁËµ«È´ÍµµÃÒ»Ãü¡£\n" NOR, ob);
		ob->set("jing", 50);	
		ob->set("eff_jing", 50);
		ob->set("qi", 50);
		ob->set("eff_qi", 50);
                ob->remove_all_killer();
		all_inventory(environment())->remove_killer(ob);
                ob->revive(1);
                return;
	}
	command("say ¶Ô²»ÆğÖ÷ÈË£¬ÎÒÎŞ·¨ÔÙ·şÊÌÄãÁË£¬ÄãÒ»¶¨ÒªºÃºÃ±£ÖØ×Ô¼º£¡");
	//tell_object(ob->query("possessed"), HIG"¶Ô²»ÆğÖ÷ÈË£¬ÎÒÎŞ·¨ÔÙ·şÊÌÄãÁË£¬ÄãÒ»¶¨ÒªºÃºÃ±£ÖØ×Ô¼º£¡\n"NOR);
	// skills - 2
	ob->skill_death_penalty();
	ob->skill_death_penalty();
	::die();
}

int do_name(string arg)
{
	object me = this_player();
	
	if (me->query("id") != query("host_id"))
		return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if (!arg || arg == "") 
		return notify_fail("ÄãÏë°ïËû¸ÄÊ²Ã´Ãû×Ö£¿\n");
	if (!living(this_object()))
		return notify_fail("ÒÔËûÄ¿Ç°µÄ×´Ì¬£¬ÔõÃ´¿ÉÄÜÌıÄãµÄÃüÁîÄØ£¿\n");
	if (!LOGIN_D->check_legal_name(arg))
		return 1;

	command("say ´Ó½ñÒÔºóÎÒ¾Í½Ğ×ö" + arg + "ÁË£¡");
	me->set("guard/name", " "+ arg+" ");
	set("name", " "+ arg+" ");
	command("thank " + me->query("id"));
	
	return 1;
}

int do_long(string arg)
{
	object me = this_player();
	string *txt;
	
	if (me->query("id") != query("host_id"))
		return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if (!arg || arg == "") 
		return notify_fail("ÄãÏë°ÑËûµÄÃèÊö¸ÄÎªÊ²Ã´£¿\n");
	if (!living(this_object()))
		return notify_fail("ÒÔËûÄ¿Ç°µÄ×´Ì¬£¬ÔõÃ´¿ÉÄÜÌıÄãµÄÃüÁîÄØ£¿\n");
	
	if (arg == "none") {
		me->delete("guard/long");
		delete("long");
		command("thank " + me->query("id"));
		return 1;
	}

	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 )
		return notify_fail("Çë½«¶ÔËûµÄÃèÊö¿ØÖÆÔÚ°ËĞĞÒÔÄÚ¡£\n");

	arg = implode(txt, "\n") + "\n";
	arg = "cmds/usr/nick"->replace_color(arg, 1);
	me->set("guard/long", arg);
	set("long", arg);
	command("thank " + me->query("id"));
	
	return 1;
}

int do_title(string arg)
{
	object me = this_player();
	
	if (me->query("id") != query("host_id"))
		return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if (!arg || arg == "") 
		return notify_fail("ÄãÏë°ÑËûµÄ³ÆºÅ¸ÄÎªÊ²Ã´£¿\n");
	if (!living(this_object()))
		return notify_fail("ÒÔËûÄ¿Ç°µÄ×´Ì¬£¬ÔõÃ´¿ÉÄÜÌıÄãµÄÃüÁîÄØ£¿\n");
	if (!check_legal_title("cmds/usr/nick"->replace_color(arg, 0)))
		return 1;

	arg = "cmds/usr/nick"->replace_color(arg, 1);
	me->set("guard/title", arg);
	set("title", arg);
	command("thank " + me->query("id"));
	
	return 1;
}

int do_ticks(string arg)
{
	object me = this_player();
	int i;
	string type, cmd, cmd1, cmd2;
	
	if (me->query("id") != query("host_id"))
		return notify_fail("ÄãÎŞÈ¨Ê¹ÓÃÕâ¸öÃüÁî£¡\n");
	if (!living(this_object()))
		return notify_fail("ÒÔËûÄ¿Ç°µÄ×´Ì¬£¬ÔõÃ´¿ÉÄÜÌıÄãµÄÃüÁîÄØ£¿\n");

	if (!arg || arg == "") {
		write(HIG"ËûÏÖÔÚµÄÕ½¶·Ö¸ÁîÕóÁĞÎª£º\n"NOR);
		for (i = 1; i <= 5; i++)
			if (stringp(cmd = me->query(sprintf("guard/status/ticks/%d", i))))
				write(sprintf("%d - %s\n", i, cmd));
			else
				write(sprintf("%d - %s\n", i, "<¿ÕÈ±>"));
		return 1;
	}

	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		return notify_fail("Ö¸Áî¸ñÊ½£ºticks [1-5 <Ö¸Áî>] | [-d 1-5|all]\n");

	if (type == "1" || type == "2" || type == "3" || type == "4" || type == "5") {
		if (sscanf(cmd, "%s %s", cmd1, cmd2) < 2)
			cmd1 = cmd;
		for (i = 0; i < sizeof(cmds); i++)
			if (cmds[i] == cmd1) {
				me->set("guard/status/ticks/" + type, cmd);
				command("en " + query("id"));
				return 1;
			}
		return notify_fail("ÄãËùÉè¶¨µÄÖ»ÄÜÊÇÕ½¶·Ö¸Áî£¡\n");
	} else if (type == "-d" && (cmd == "1" || cmd == "2" || cmd == "3" || cmd == "4" || cmd == "5"))
		me->delete("guard/status/ticks/" + cmd);
	else if (type == "-d" && cmd == "all")
		for (i = 1; i <= 5; i++)
			me->delete(sprintf("guard/status/ticks/%d", i));
	else
		return notify_fail("Ö¸Áî¸ñÊ½£ºticks [1-5 <Ö¸Áî>] | [-d 1-5|all]\n");

	command("en " + query("id"));
	
	return 1;
}

int check_legal_title(string name)
{
	int i = strlen(name);
	
	if( (strlen(name) < 8) || (strlen(name) > 20 ) ) {
		write("¶Ô²»Æğ£¬³ÆºÅ±ØĞëÊÇ 4 µ½ 10 ¸öÖĞÎÄ×Ö¡£\n");
		return 0;
	}

	while(i--) {
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("¶Ô²»Æğ£¬³ÆºÅ²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
			return 0;
		}
		if( (strsrch(name, "¡¡") >= 0) ||
		    (strsrch(name, "°Ö") >= 0)) {
			write("¶Ô²»Æğ£¬³ÆºÅ²»ÄÜÓÃÒıÆğÎó»áµÄµ¥×Ö¡£\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("¶Ô²»Æğ£¬³ÆºÅ±ØĞëÊ¹ÓÃÖĞÎÄ×Ö¡£\n");
			return 0;
		}
	}
	return 1;
}
