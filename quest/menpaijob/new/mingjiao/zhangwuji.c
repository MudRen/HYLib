//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
int ask_job2();
int ask_fail2();

mixed jobs = ({
        ({
"ÎÒÈñ½ðÆìÔÚ½ÌÄÚ¸ºÔð²É¿óÁ¶Ìú£¬×î½üÉÏµÈ¾«Ìú¿ìÓÃÍêÁË£¬ÐèÒª²É¼¯Ìú¿ó",
"ÄãÀ´µÄÕýºÃ£¬ÐÖµÜÃÇÑÝÁ·Õó·¨£¬¾ÞÄ¾²»¹»ÁË£¬ÄãÈ¥Ê÷ÁÖÀï¿³Ð©Ê÷¸É¿¸»ØÀ´",
"ÔÛÃÇºñÍÁÆì¸ºÔðÍÚµØµÀ£¬½«À´»áÓÐ´óÓÃ³¡¡£ÄãÈ¥¸úµÜÐÖÃÇÒ»Æð½«µØµÀÍÚÉîµã",
"ÎÒºéË®ÆìÔÚ½ÌÄÚ¸ºÔðÖÆÔì¶¾Ë®£¬×î½ü±ùË®¿ìÓÃÍêÁË£¬ÄãÈ¥±ÌË®º®Ì¶È¡Ð©Ë®À´",
"ÐÖµÜÃÇÐÁÐÁ¿à¿àÁ¶³öÀ´Ò»Ð©¾«Ìú£¬ÄãÈ¥ÓÃËüºÃºÃ´òÔì»ðÇ¹",
        }),
        ({
         "Ð¡ÕÑ","ÑîåÐ","·¶Ò£","ÒóÌìÕý","Ð»Ñ·","ÀäÇ«","ÅíÓ¨Óñ","ÖÜµß","ÕÅÖÐ",
	"Ëµ²»µÃ","×¯ï£","ÎÅ²ÔËÉ","ÌÆÑó","ÐÁÈ»","ÑÕÔ«","ÒóÒ°Íõ","ÒóËØËØ",
	 "ÀîÌìÔ«","³Ì³°·ç","¸ßÉ½Íõ","³£½ðÅô","°×¹êÊÙ","·â¹­Ó°","ºúÇàÅ£","×¯ï£",
	 "ÎÅ²ÔËÉ","ÌÆÑó","ÐÁÈ»","ÑÕÔ«","×¯ï£","ÎÅ²ÔËÉ","ÌÆÑó","ÐÁÈ»",
        }),
        });
#include "teamjob.c"
void greeting(object ob);
void create()
{
    seteuid(getuid());
    set_name("ÕÅÎÞ¼É", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", "Ã÷½Ì½ÌÖ÷ÕÅÎÞ¼É£¬Í³ÁìÌìÏÂÊ®Íò½ÌÖÚ£¬ºÀÆø¸ÉÔÆ£¬ß³ßåÇ§Çï£¬\n"
               +"¡¸¾ÅÑôÉñ¹¦¡¹¡¢¡¸Ç¬À¤´óÅ²ÒÆ¡¹¶À²½ÌìÏÂ£¬ÊÇ½­ºþÖÐ²»ÊÀ³öµÄ\n"
               +"ÉÙÄêÓ¢ÐÛ¡£\n");
    set("title",HIG "Ã÷½Ì"HIM"½ÌÖ÷"NOR);
    set("gender", "ÄÐÐÔ");
    set("age", 20);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("per", 28);
    set("str", 36);
    set("int", 36);
    set("con", 30);
    set("dex", 30);

    set("qi", 4050);
    set("max_qi", 4050);
    set("jing", 4050);
    set("max_jing", 4050);
    set("neili", 18000);
    set("max_neili", 18000);
    set("jiali", 120);

    set("combat_exp", 9900000);
    set("score", 455000);
    
    set_skill("force", 250);
    set_skill("unarmed", 200);
    set_skill("dodge", 200);
    set_skill("parry", 220);
    set_skill("hand",200);
    set_skill("sword",250);
    set_skill("blade", 200);
    set_skill("cuff", 250);
    set_skill("jiuyang-shengong", 300);
    set_skill("qiankun-danuoyi", 300);
    set_skill("qishang-quan", 300);
    set_skill("shenghuo-shengong", 300);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",300);

    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","shenghuo-ling");
    map_skill("blade","taiji-dao");

    create_family("Ã÷½Ì",34, "½ÌÖ÷");

    set("chat_chance",2);
    set("chat_msg",({
 "ÕÅÎÞ¼É·ßÈ»ËµµÀ¡°´óÕÉ·òµ±ÒÔ¹úÎª¼Ò, ¾èÇûÉ³³¡, ¿¹Ôª´óÒµÎ´³É, Í¬±²ÈÔÐèÅ¬Á¦!¡±\n",
        "ÕÅÎÞ¼ÉÌ¾µÀ¡°ÈËÉúÊ§Ò»Öª¼º, ÉúÒàºÎ»¶, ËÀÒàºÎÓÇ, Ãô¶ù, ÄãÔÚÄÄÀï?¡±\n",
        "ÕÅÎÞ¼ÉµÀ¡°ÎÒ½ÌÐÖµÜÌýÁË: ÉúÓÚÂÒÊÀ, µ±¿Ë¼ºÎª¹«, ÐÐÏÀÕÌÒå, µ´¿ÜÇýÄ§!¡±\n",
//        	(: random_move :)
    }));

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: command("unwield ling") :),
                (: command("unwield ling") :),
                (: command("wield ling") :),
                (: command("wield ling") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
    set("inquiry",([
	  "Ã÷½Ì" :     "Ã÷½ÌÕýÔÚ±àÐ´Ö®ÖÐ£¬Çë¾ýÉÔºò¡£\n",
          "½ðÃ«Ê¨Íõ" : "ÄÇÊÇÎÒÒå¸¸Ð»´óÏÀµÄÖ°Ë¾¡£\n",
          "Ð»Ñ·" :     "Ëû¾ÍÊÇÎÒÒå¸¸µÄ´óºÅ¡£\n",
          "ÕÅ´äÉ½" :   "ÄãÏëÕÒÎÒ¸¸Ç×ÓÐÊÂ÷á? \n",
          "ÒóËØËØ" :   "ÎÒÂèÊÇÃ÷×ð×ùÏÂ×ÏÎ¢ÌÃÖ÷¡£\n",
          "ÕÅÈý·á" :   "ÎÒÌ«Ê¦¸¸½üÀ´¿ÉºÃ? \n",
          "ÕÔÃô" :     "ÈËÉúÊ§Ò»Öª¼º, ÉúÒàºÎ»¶, ËÀÒàºÎÓÇ, Ãô¶ù, ÄãÔÚÄÄÀï?\n",
          "Ð¡ÕÑ" :     "Ð¡ÕÑÎÒ¿ÉÒ»Ö±Äî×ÅËýµÄºÃ´¦¡£\n",
          "ÖÜÜÆÈô" :   "ÕÒËý¾ÍÈ¥¶ëáÒÉ½, ±ðÀ´·³ÎÒ¡£\n",
		 "job"  : (: ask_jianxi :),
                "Á·±ø" : (: ask_job2() :),
                "mjjob" : (: ask_job2() :),
                "²»Á·±øÁË" : (: ask_fail2() :),
                "fail" : (: ask_fail2() :),


    ]));
    setup();
    carry_object("/d/mingjiao/obj/yitianjian");
    carry_object("/clone/book/shenghuo-ling")->wield();
//    	carry_object("/d/mingjiao/obj/jiaozhumingpao")->wear();
    add_money("silver",70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
//      command("say
	command("wield yitian jian");
	command("hit"+(string)ob->query("id"));
        command("unwield yitian jian");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say Ä§´ÓÐÄÆð£¬ÓÚÎäÑ§²»Àû£¬ÆäµÀ±ØÖï£¬È°¾ý·ÅÏÂÍÀµ¶£¬Á¢µØ³É·ð.");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say ÕâÎ»ÅóÓÑ£¬ÈËÐÐ½­ºþ£¬ÑÔÐÐµ±Õý£¬ÇÐÎñ×ß½øÐ°Ä§ÍáµÀ.");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say ¹âÃ÷ÕýµÀÈÎÈË×ß£¬È°¾ý¶à¼Ó±£ÖØ.");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say ´óÏÀÔÚÉÏ£¬ÊÜÎÞ¼ÉÒ»Àñ£¬´óÏÀËüÈÕ±ØÎªÎäÁÖÇÌ³þ.");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say ÄãµÄÎòÐÔÌ«µÍÁË£¬²»ÊÊºÏÑ§Ï°ÎÒµÄ¹¦·ò¡£");
		return 0;
	}
	if((string)ob->query("gender")=="ÎÞÐÔ")
	{
		command("say ÄãÑôÆø²»×ã£¬Ï°ÎÒ¹¦·ò¿Ö½«×ß»ðÈçÄ§¡£");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say ÄãÓ¦µ±¶à×÷Ð©ÐÐÏÀÕÌÒåµÄÊÂ£¬ÒÔÐÞÉíÐÄ¡£");
		return 0;
	}
	command("say ºÃ£¬ÎÒ¾ÍÊÕÏÂÄãÕâÎ»ºÃÍ½µÜ£¡");
	command("say ÄãµÄÖ°Ë¾¾ÍÊÇ±¾½ÌµÄ¹âÃ÷Ê¹Õß¡£");
	command("recruit " + ob->query("id"));
	ob->set("title", HIR"Ã÷½ÌÊ¹Õß"NOR);
	return;
}

int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("ÎäÁÖÖÐÈË×î¼ÉÕùÇ¿¶·ºÝ£¬Äã²»ÊÇÎÒµÄ¶ÔÊÖ£¬»ØÈ¥°É¡£\n",ob);
        return 0;
    }
    message_vision("ÕÅÎÞ¼ÉÒ»¹°ÊÖËµµÀ£ºÕâÎ»"+RANK_D->query_respect(ob)+
	"£¬ÔÚÏÂÁì½ÌÁË¡£\n", ob);
    return 1;
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("ÄãÃ»ÓÐÕâ¼þ¶«Î÷¡£");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ÄãÄÃ¸ö¿ìËÀµÄÈËÀ´Æ­ÎÒ£¿");
       return 0;
       }
   if(obj->query("id") == "ling qi" && me->query("mjjob") == 1)
   {
       command("nod "+(string)me->query("id"));
       command("say ¸ÉµÃºÃ£¡\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }
    if(me->query("mjjob") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say ²»´í°¡£¬µ«Õâ»îÎÒÃ»½ÐÄã¸É°¡¡£");
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ÎÒÒªÇ®¸ÉÊ²Ã´?");
       return 0;
       }
   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 15;
   exp = 1200 + kar;
   pot = 600 + random(exp);

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say ß×£¬ÈËÄØ£¿");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N¶Ô$nËµµÀ£ºÄãÕâ´Î×öµÃ¼«Îª³öÉ«£¡ÎÒ¾ÍÖ¸µãÄãÁ½ÊÖ¹¦·ò°É.\n"NOR,ob, me);
                  message_vision(HIC "\nÓÉÓÚ$N³É¹¦µÄÏûÃðÁËÎå´óÃÅÅÉµÄÈËÂí£¬±»½±Àø£º\n"
                + chinese_number(exp / 2) + "µãÊµÕ½¾­Ñé£¬\n"
                + chinese_number(pot / 2) + "µãÇ±ÄÜ£¬\n"
                + chinese_number(50) + "µãÆÀ¼Û×÷Îª´ðÐ»¡£\n" NOR, me);
                me->add("combat_exp", exp / 2);
                me->add("potential", pot / 2);
                me->add("score",50);
                ckiller=3;
destruct(present("ling qi",ob));
   	        me->apply_condition("mingjiaojob",0);
//
//                me->delete("quest");
                me->delete("mjjob");
   return;      
}

int ask_job2()
{

        object me = this_player();
        object ob;
string skl,tar;

        skl = me->query_skills();

        if( me->query("family/family_name") != "Ã÷½Ì")
           {
                      message_vision("$N¶Ô×Å$nËµµÀ¡£ÕâÖÖÊÂ¿ÉÒÔÓÐÀÍ±ðÈË´øÐÐ£¿\n", this_object(), me);
                      return 1;
            }

        if ( !skl ) {
                tell_object(me, "ÄãÈ¥Ñ§Ò»Ð©±¾ÊÂÏÈ°É£¡\n");
                return 1;
                }

        if ((int)me->query_condition("mj2_busy"))  
            {
                      message_vision("$N¶Ô×Å$nÒ¡ÁËÒ¡Í·Ëµ£ºÄã¸ÕÒª¹ýÈÎÎñ,µÈ»áÔÙÀ´!\n", this_object(), me);
                      return 1;
            }

        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ÄãµÄÇ±ÄÜÌ«ÉÙÁË!!");
                return 1;
        }

        if (me->query_temp("mj2job")) {
                command("kick " + me->query("id"));
                command("say ÎÒ²»ÊÇ¸øÁËÄãÈÎÎñÁËÂð£¿");
                return 1;
                }
        else {

tar = jobs[1][random(sizeof(jobs[1]))];
skl = jobs[0][random(sizeof(jobs[0]))];        
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "  ÎÒ½ÌÄ¿µÄÔÚÓë·´¿¹Ôª±ø£¬ÏÖÔÚÕýÔÚÁ·±ø  £");
                command("say " + me->query("id") + " ¡º" + skl  + "¡»£¡" NOR);
                command("say " + me->query("id") + "  ÎÒ½Ì¡º" + tar  + "¡»ÕýÔÚ×öÕâ¼þÊÂ£¬ÄãÈ¥Ð­Öú(xiezhu)Ëû°É£¡" NOR);
        me->delete_temp("mjjob2");
                me->set_temp("mj2job", tar);
                ob = new(__DIR__"ling");
                ob->set("usename",me->query("name"));
                ob->move(me);
                command("say " + me->query("id") + "  Õâ¸öÎåÐÐÆì£¬ÄãÄÃºÃ£¬Æ¾Õâ¸öÈ¥×ö°É£¡" NOR);
                return 1;
               }                              
}

int ask_fail2()
{
        object me = this_player();
        
        if (me->query_temp("mj2job")) {
                command("sigh");
                command("say ÕâÃ´µãÊÂ£¬Äã¶¼×ö²»ºÃ£¬Ò²°Õ£¬ÄãÈ¥°É.");
                me->apply_condition("mj2_busy", 5 +
                        (int)me->query_condition("mj2_busy"));

me->delete_temp("mj2job");
me->delete_temp("mj2skl");
me->delete_temp("mj2jobs");
                return 1;
                }
}
