#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#define __THD__ "/d/taohua/"

void consider();
string ask_me();
int ask_marry();
int ask_test1();
int ask_test2();
int ask_test3();
int ask_nvxu();

int ask_zhou();

void create()
{
    set_name("»ÆÒ©Ê¦", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", "ÌÒ»¨µºÖ÷");
    set("nickname", HIY "¶«Ğ°" NOR );
    set("gender", "ÄĞĞÔ");
    set("age", 42);
        set("long", 
                "Ëû¾ÍÊÇÌÒ»¨µºµÄµºÖ÷£¬½­ºşÉÏÈËÈËÎÅÃû±äÉ«µÄ¶«Ğ°»ÆÒ©Ê¦¡£\n"
                "ËûÉí´©Ò»¼şÇàÉ«³¤ÅÛ£¬Ñü´øÉÏĞ±²å×ÅÒ»Ö»Óñóï¡£\n"
                "ËûĞÎÏàÇåñ³£¬·á×ËöÁË¬£¬ÏôÊèĞù¾Ù£¬Õ¿È»ÈôÉñ¡£\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 61);
    set("int", 60);
    set("con", 66);
    set("dex", 60);
    set("per", 60);

    set("chat_chance", 1);
    set("chat_msg", ({
        "»ÆÒ©Ê¦Ì¾ÁË¿ÚÆøµÀ£º¡°°¦ ¡­¡­ ÈØ¶ùÕâ¿àÃüµÄº¢×Ó£¬´ÓĞ¡¾ÍÃ»ÁËÄï ¡­¡­¡±\n",
        "»ÆÒ©Ê¦µÍÍ·³ÁË¼£¬ÓÆÈ»²»Óï¡£\n",
    }));
/*    set("inquiry", ([
        "»ÆÈØ"     : "Äã¸ÒÖ±³ÆÎÒÅ®¶ùµÄ¹ëÃû£¿ \n",
        "¾ÅÒõÕæ¾­" : "Èç¹ûÄãÄÜ°ïÎÒÈ¡µÃÕæ¾­ÉÏ²á£¬ÎÒÒ»¶¨ÖØÖØĞ»Äã¡£\n",
    ]));*/

    set("qi", 29000);
    set("max_qi", 29000);
    set("jing", 18000);
    set("max_jing", 18000);
    set("neili", 53500);
    set("max_neili", 53500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 9000000);
    set("score", 0);
	 
    set_skill("leg", 380);             // »ù±¾ÄÚ¹¦
    set_skill("force", 280);             // »ù±¾ÄÚ¹¦
    set_skill("bibo-shengong", 380);     // ±Ì²¨Éñ¹¦
    set_skill("claw", 200);              // »ù±¾×¦·¨
    set_skill("hand", 320);              // »ù±¾ÊÖ·¨
    set_skill("finger", 320);            // »ù±¾Ö¸·¨
    set_skill("tanzhi-shentong", 380);   // µ¯Ö¸ÉñÍ¨
    set_skill("unarmed", 280);           // »ù±¾È­½Å
    set_skill("strike", 280);            // »ù±¾È­½Å
    set_skill("luoying-zhang", 380);     // ÂäÓ¢Éñ½£ÕÆ
    set_skill("xuanfeng-leg", 380);      // Ğı·çÉ¨Ò¶ÍÈ
    set_skill("dodge", 280);             // »ù±¾¶ãÉÁ
    set_skill("anying-fuxiang", 380);    // °µÓ°¸¡Ïã
    set_skill("parry", 200);             // »ù±¾ÕĞ¼Ü
    set_skill("sword", 320);             // »ù±¾½£·¨
    set_skill("luoying-shenjian", 380);  // ÂäÓ¢Éñ½£
    set_skill("yuxiao-jian", 380);       // Óñóï½£·¨
    set_skill("lanhua-shou", 380);       // À¼»¨·÷Ñ¨ÊÖ
    set_skill("qimen-wuxing",380);       // ÆæÃÅÎåĞĞ
    set_skill("count",380);              // ÒõÑô°ËØÔ
    set_skill("literate",380);           // ¶ÁÊéÊ¶×Ö
	  set_skill("chixin-jian", 380);             // »ù±¾ÄÚ¹¦
    set_skill("canglang-bian", 380);             // »ù±¾ÄÚ¹¦
    set_skill("whip", 380);             // »ù±¾ÄÚ¹¦
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("whip"   , "canglang-bian");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "chixin-jian");
    map_skill("parry"  , "luoying-zhang");    	

if (random(3)==0)
{
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");
}
else
{
	prepare_skill("finger", "tanzhi-shentong");
	prepare_skill("hand", "lanhua-shou");	
}
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "qimenzhen" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
		(: command("unwield yuxiao") :),
		(: command("wield yuxiao") :),
		(: command("unwield bian") :),
(: command("wield bian") :),
(: perform_action, "finger.ding" :), 
	(: perform_action, "finger.zhuan" :), 
(: perform_action, "sword.muyu" :),                
	(: perform_action, "sword.nosword" :),                
		(: perform_action, "sword.trhy" :),                
		(: perform_action, "whip.duoming" :),                
		(: perform_action, "whip.lang" :),                
		(: perform_action, "whip.tlyj" :),                
		(: perform_action, "whip.yljx" :),                									
 
        }));
    set("inquiry", ([
                "name": "ÄÑµÀÌìµ×ÏÂ¾ÍÃ»ÈËÖªµÀÎÒ¶«Ğ°»ÆÒ©Ê¦µÄÃû×ÖÁËÂğ£¿",
                "rumors": "ÌıËµÈ«Õæ½ÌÄÇ°ïÅ£±Ç×ÓÔÚµ½´¦ÕÒÖÜ²®Í¨£¬ºß£¡",
                "¶«Ğ°": "ÄÇ¶¼ÊÇ½­ºşÉÏÄÇ°àÂú×ìÈÊÒåµÀµÂµÄ¼Ò»ï¸øÎÒÆğµÄ´ÂºÅ¡£",
                "Î÷¶¾": "ÒÔÇ°µÄÎ÷¶¾ÊÇÅ·Ñô·æÄÇÖ»³ô¸òó¡£¬³ıÁË»áË£Á½ÊÖÉßÍâ£¬Ã»Ê²Ã´Õæ¹¦·ò¡£",
                "Å·Ñô·æ": "ÄÇÖ»³ô¸òó¡£¬³ıÁË»áË£Á½ÊÖÉßÍâ£¬Ã»Ê²Ã´Õæ¹¦·ò¡£",
                "ÄÏµÛ": "ÒÔÇ°µÄÄÏµÛÊÇ´óÀíµÄÍõÒ¯¶ÎÖÇĞË£¬ÏÖÔÚ³ö¼Ò×öºÍÉĞ£¬¸Ä½ĞÒ»µÆÀ²¡£",
                "Ò»µÆ": "ÒÔÇ°ÊÇ´óÀíµÄÍõÒ¯¶ÎÖÇĞË£¬ÏÖÔÚ³ö¼Ò×öºÍÉĞ£¬¸Ä½ĞÒ»µÆÀ²¡£",
                "¶ÎÖÇĞË": "ÒÔÇ°ÊÇ´óÀíµÄÍõÒ¯£¬ÏÖÔÚ³ö¼Ò×öºÍÉĞ£¬¸Ä½ĞÒ»µÆÀ²¡£",
                "±±Ø¤": "ÒÔÇ°µÄ±±Ø¤ÊÇºéÆß¹«ÄÇ¸öÀÏ½Ğ»¯£¬¼¸ÊÖ½µÊ²Ã´Ê®°ËÕÆµ¹»¹Ê¹µÃ¡£",
                "ºéÆß¹«": "ÄÇ¸öÀÏ½Ğ»¯ÊÇØ¤°ï°ïÖ÷£¬¼¸ÊÖ½µÊ²Ã´Ê®°ËÕÆµ¹»¹Ê¹µÃ¡£",
                "ÖĞÉñÍ¨": "ÒÔÇ°µÄÖĞÉñÍ¨ÊÇÈ«Õæ½ÌµÄ³ôµÀÊ¿ÍõÖØÑô£¬Òª²»ÊÇÀÏ·òÒ»Ê±Ê§ÊÖ£¬ÎäÁÖµÚÒ»µÄ³ÆºÅÒ²²»»á±»ËûÇÀ×ß¡£",
                "ÍõÖØÑô": "ÊÇÈ«Õæ½ÌµÄ³ôµÀÊ¿£¬Òª²»ÊÇÀÏ·òÒ»Ê±Ê§ÊÖ£¬ÎäÁÖµÚÒ»µÄ³ÆºÅÒ²²»»á±»ËûÇÀ×ß¡£",
                "ÖÜ²®Í¨": "Õâ¸ö´óÉµ¹Ï£¬±»ÎÒÆ­ÁË¶¼²»ÖªµÀ£¬ÄãÈç¹ûÏëÕÒËû£¬ºÙºÙºÙ....",
                "ÀÏÍçÍ¯": "Õâ¸ö´óÉµ¹Ï£¬±»ÎÒÆ­ÁË¶¼²»ÖªµÀ£¬ÄãÈç¹ûÏëÕÒËû£¬ºÙºÙºÙ....",
                "»ÆÈØ": "°¦£¬´ÓĞ¡¾Í¶ÔËı½¿Éú¹ßÑø£¬ÏÖÔÚËıµ÷Æ¤ÈÎĞÔ£¬ÎÒÒ²Ã»°ì·¨ÁË¡£",
                "ÈØ¶ù": "°¦£¬´ÓĞ¡¾Í¶ÔËı½¿Éú¹ßÑø£¬ÏÖÔÚËıµ÷Æ¤ÈÎĞÔ£¬ÎÒÒ²Ã»°ì·¨ÁË¡£",
                "¹ù¾¸": "±ğÌáÎÒÕâ¸öÉµÅ®ĞöÁË¡£",
                "Å®Ğö": (: ask_nvxu :),
                "³Ë·ç": "ÊÇÎÒµÄËÄµÜ×Ó£¬ÏÖÔÚ×¡ÔÚ¹éÔÆ×¯¡£",
                "Â½³Ë·ç": "ÊÇÎÒµÄËÄµÜ×Ó£¬ÏÖÔÚ×¡ÔÚ¹éÔÆ×¯¡£",
                "»ÆÒ©Ê¦": "¾ÍÊÇÀÏ·òÎÒ¡£ÔõÃ´£¬²»·şÂğ£¿ÔÛÁ©Á·Á·£¿",
                "¾Å¹¬": "¾Å¹¬Ö®Òå£¬·¨ÒÔÁé¹ê¡£¶şËÄÎª¼ç£¬Áù°ËÎª×ã£»×óÈıÓÒÆß£¬´÷¾ÅÂÄÒ»£»Îå¾ÓÖĞ¼ä¡£",
                "°ËØÔ": "Ç¬ÈıÁ¬£¬À¤Áù¶Î£»ÀëÖĞĞé£¬¿²ÖĞÂú£»ÕğÑöÓÛ£¬ôŞ¸²Íë£»¶ÒÉÏÈ±£¬ÙãÏÂ¶Ï¡£",
                "ÎåĞĞ": "½ğÉúË®£¬Ë®ÉúÄ¾£¬Ä¾Éú»ğ£¬»ğÉúÍÁ£¬ÍÁÉú½ğ¡£½ğ¿ËÄ¾£¬Ä¾¿ËÍÁ£¬ÍÁ¿ËË®£¬Ë®¿Ë»ğ£¬»ğ¿Ë½ğ¡£",
                "Ò×¾­": "ÊÇÒ»±¾½²½â·üôËÁùÊ®ËÄØÔµÄÆæÊé£¬Ò»°ãÈËÄÑµÃ¿´¶®¡£",
                "ÖÜÒ×": "ÊÇÒ»±¾½²½â·üôËÁùÊ®ËÄØÔµÄÆæÊé£¬Ò»°ãÈËÄÑµÃ¿´¶®¡£",
                "¾ÅÒõÕæ¾­": "Äã´òÌıÕâ¸ö¸ÉÊ²Ã´£¿£¡",
                "ºÍÉĞ": "ÀÏ·òÎÒ¶ÔºÍÉĞ¾ÍÊÇÇÆ²»¹ß£¡",
                "Çó»é": (: ask_marry :),
                "µÚÒ»¹Ø": (: ask_test1 :),
                "test1": (: ask_test1 :),
                "µÚ¶ş¹Ø": (: ask_test2 :),
                "test2": (: ask_test2 :),
                "µÚÈı¹Ø": (: ask_test3 :),
                "test3": (: ask_test3 :),
        "ÃØ¼®" : (: ask_me :),
        "Ğı·çÉ¨Ò¶ÍÈ·¨" : (: ask_me :),
      	"ÖÜ²®Í¨": (: ask_zhou :),
    ]));


    create_family("ÌÒ»¨µº", 1, "µºÖ÷");
    setup();
	
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
if (random(3)==0)
{	
	 carry_object(__DIR__"obj/yuxiao")->wield();
carry_object(__DIR__"obj/hlbian");
}
else
{
carry_object(__DIR__"obj/hlbian")->wield();
carry_object(__DIR__"obj/yuxiao");
}
    carry_object(__DIR__"obj/bupao")->wear();
//    carry_object("clone/book/jiuyin2");
    
}

void attempt_apprentice(object ob)
{
        string old_name, new_name;
    if (ob->query_int() < 30) {
        command("say ÎÒ²»ÊÕ×ÊÖÊ²îµÄµÜ×Ó£¬ÄúÇë»Ø°É£¡");
		return;
    }
        if (ob->query("gender") != "ÄĞĞÔ" && ob->query("gender") != "Å®ĞÔ") {
                command("say Äã²»ÄĞ²»Å®µÄËãÊ²Ã´¶«Î÷£¿¿ì¹ö£¡");
                return;
        }
        if (ob->query("shen") <= -200000) {
                command("say ÎÒÉúÆ½×îÌÖÑáÁ½ÖÖÈË£¬ÄãÃÇÕâÖÖÎŞ¶ñ²»×÷µÄĞ°Ä§ÍâµÀ¾ÍÊÇÆäÒ»£¬ºß£¡");
                return;
        }
        if (ob->query("shen") >= 200000) {
                command("say ÎÒÉúÆ½×îÌÖÑáÁ½ÖÖÈË£¬ÄãÃÇÕâÖÖ×ÔÃü´óÏÀµÄ¹ÁÃûµöÓşÖ®Í½¾ÍÊÇÆäÒ»£¬ºß£¡");
                return;
        }
        if (ob->query_int() < 28) {
                command("say ¿´ÄãÕâ¸±Ä£Ñù£¬±ÈÎÒÄÇÉµÅ®Ğö»¹±¿£¬»¹Ïë°İÎÒÎªÊ¦£¿");
                return;
        }
        if (!ob->query_skill("literate")) {
                command("say ÄãÕâ¸öÎÄÃ¤Ò²ÏëÀ´Ñ§¹¦·ò£¿ÏÈÈ¥Ñ§µãÎÄ»¯°É¡£");
                return;
        }


        if (ob->query("class") == "bonze") {
                if (ob->query("family/family_name") == "ÉÙÁÖÅÉ")
                        command("say ÄãÃÇ×ÔÃüÌìÏÂÎä¹¦³öÉÙÁÖ£¬ÎÒÕâÀïµÄÃíĞ¡£¬¿É²»¸ÒÊÕÄã¡£");
                else
                        command("say ÎÒ¶«Ğ°×îÌÖÑáºÍÉĞ£¬¿´µ½¹âÍ·¾ÍÓĞÆø£¬ËùÒÔÁ¬Äá¹Ã¡¢À®ÂïÒ»Æğ¶¼²»ÊÕ¡£");
                return;
        }

    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say ÄãµÄ±¾ÃÅÄÚ¹¦ĞÄ·¨Ì«µÍÁË,»¹ÊÇÅ¬Å¬Á¦ÏÈÌá¸ßÒ»ÏÂ°É!");
		return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say ÎÒÌÒ»¨µºÓëÊÀ¸ô¾ø£¬ÏòÀ´²»ÓëÄúÕâÖÖ³ÉÃûÈËÎï´ò½»µÀ£¬ÄúÇë»Ø°É£¡");
		return;
	}

    command("say ºÜºÃ£¬ºÜºÃ¡£");
    command("recruit " + ob->query("id"));
                command("chat ¹ş¹ş¹ş¹ş£¡£¡£¡£¡");
                command("chat Ïë²»µ½ÎÒ¶«Ğ°ÎóÖğµÜ×ÓÖ®ºó£¬»¹ÄÜµÃ´ËÁ¼²ÅÃÀÖÊ£¬ÕæÊÇ¿ÉÏ²¿ÉºØ¡£");
                command("recruit " + ob->query("id"));
                old_name = ob->query("name");
                new_name = old_name[0..3] + "·ç";
                ob->set("name", new_name);
                say(old_name + "°İÈë»ÆÒ©Ê¦ÃÅÏÂ£¬Î»ÁĞ¶ş´úµÜ×Ó¡°·ç¡±×Ö±²£¬ÆğÃûÎª" + new_name + "¡£\n");

}

int recognize_apprentice(object ob)
{
	mapping myfam;
       	myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "ÌÒ»¨µº") return 1 ;
	if ((int)ob->query_temp("tmark/»Æ") == 1 )
        message_vision("»ÆÒ©Ê¦¿´ÁË¿´$N£¬ËµµÀ£ºÔÛÃÇÏÖÔÚÊÇË­Ò²²»Ç·Ë­,\n"
                          "Äã²»ÒªÔÙÕÒÎÒÑ§Ï°¼¼ÒÕÁË¡£\n", ob);
	if (!(int)ob->query_temp("tmark/»Æ"))
		return 0; 
	ob->add_temp("tmark/»Æ", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jiuyin zhenjing1" ) {
 		if (!(int)who->query_temp("tmark/»Æ")) who->set_temp("tmark/»Æ", 0);
		message_vision("»ÆÒ©Ê¦¿´ÁË¿´$NËÍÀ´µÄÃØ¼®£¬µãÁËµãÍ·£¬ËµµÀ£º\n"
                               "ÄÑµÃÄã½«Õæ¾­ËÍ»Ø¡£ÄãËÍÎÒµÄ¶«Î÷ÎÒ¾ÍÊÕÏÂÁË¡£\n"
                               "×÷Îª²¹³¥,Äã¿ÉÒÔ´ÓÎÒÕâÀïÑ§µã¹¦·ò¡£\n", who);
		who->add_temp("tmark/»Æ", 120);
		return 1;
	}
	return 0;
}
string ask_me()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(this_player()) + 
		"·ÇÎÒµÜ×Ó£¬²»Öª´Ë»°´ÓºÎÌ¸Æğ£¿";
	if (query("book_count") < 1)
		return "ÄãÀ´ÍíÁË£¬±¾ÅÉµÄÃØ¼®²»ÔÚ´Ë´¦¡£";
	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"ÄÃµ½Ğı·çÉ¨Ò¶ÍÈ·¨À²¡£\n");
	return "ºÃ°É£¬Õâ±¾¡¸Ğı·çÉ¨Ò¶ÍÈ·¨¡¹ÄãÄÃ»ØÈ¥ºÃºÃ×êÑĞ¡£";
}
//void die()
//{
//message("channel:rumor", MAG"¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+this_player()->query("name")+"ÇÀÁË¾ÅÒõÕæ¾­ÏÂ¾íÀ²¡£\n"NOR, users());
//	::die();
//}
int ask_zhou()
{
	command("say Õâ¼Ò»ïÓĞ¾ÅÒõÕæ¾­µÄÉÏ¾í£¬¾ÍÊÇËÀÒ²²»¿Ï½»³öÀ´¡£");
	command("sneer");
	command("say ÎÒ½«ËûÀ§ÔÚµºÉÏ£¬¿´ËûÄÜ³Åµ½¼¸Ê±£¡");
	this_player()->set_temp("jiuyin/huang", 1);
	return 1;
}
void init()
{
        object ob = this_player();

        add_action("do_answer","answer");
        add_action("do_answer","huida");
        ::init();

}


int ask_marry()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0, user_exist = 1;

        if (ob->query("gender") != "ÄĞĞÔ" && ob->query("gender") != "Å®ĞÔ") {
                command("sneer " + ob->query("id"));
                command("say ÄãÒ²ÏëÈ¢ÀÏÆÅ£¿ÏÂ±²×Ó°É£¡");
                return 1;
        }
        if (ob->query("gender") == "Å®ĞÔ") {
                command("say Äãµ±ÎÒÅ®¶ùÊÇÍ¬ĞÔÁµ°¡£¿¿ì¹ö£¡");
                return 1;
        }
        if (ob->query("class") == "bonze") {
                command("sneer " + ob->query("id"));
                command("say ºÍÉĞÒ²¶¯ÁË·²ĞÄ£¬ÏëÈ¢ÀÏÆÅ£¿ÏÈ»¹Ë×ÔÙËµ°É£¡");
                return 1;
        }
        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id) {
                if (id == ob->query("id") && nvxu->query("death_count") == ob->query("death_count")) {
                        say(CYN"»ÆÒ©Ê¦Ğ¦µÀ£º" + RANK_D->query_rude(ob) + "£¬»¹²»¿ì½ĞÔÀ¸¸£¿£¡\n"NOR);
                        return 1;
                }
                if (!(user = find_player(id))) {
                        user = new(USER_OB, id);
                        user->set_name("", ({ id }));
                        if (!user->restore()) {
                                destruct(user);
                                user_exist = 0;
                        }
                        else user_load = 1;
                }
/*                if (user_exist && nvxu->query("death_count") == user->query("death_count")) {
                        command("say Ğ¡Å®ÒÑ¾­ĞíÅä¸ø" + nvxu->query("name") + "ÁË¡£");
                        if (user_load) destruct(user);
                        return 1;
                }*/
                if (user_load) destruct(user);
        }
        if (ob->query("marry")) {
                command("sneer " + ob->query("id"));
                command("say Äã²»ÊÇÒÑ¾­È¢ÁËÆŞ×ÓÁËÂğ£¿ÎÒ×îºŞ¸ºĞÄ±¡ĞÒµÄÈË£¬ÔÙÀ´ÂŞàÂ£¬Ğİ¹ÖÀÏ·òÎŞÀí£¡");
                return 1;
        }
        if ((int)ob->query("shen") <= -200000) {
                command("say ÎÒÉúÆ½×îÌÖÑáÁ½ÖÖÈË£¬ÄãÃÇÕâÖÖÎŞ¶ñ²»×÷µÄĞ°Ä§ÍâµÀ¾ÍÊÇÆäÒ»£¬ºß£¡");
                return 1;
        }
        if ((int)ob->query("shen") >= 200000) {
                command("say ÎÒÉúÆ½×îÌÖÑáÁ½ÖÖÈË£¬ÄãÃÇÕâÖÖ×ÔÃü´óÏÀµÄ¹ÁÃûµöÓşÖ®Í½¾ÍÊÇÆäÒ»£¬ºß£¡");
                return 1;
        }
        if (ob->query("age") > 49) {
                command("sneer " + ob->query("id"));
                command("say ÄãÕâÃ´¸öÔãÀÏÍ·Ò²Ïë×öÎÒÅ®Ğö£¿¸É´àÎÒ×öÄãÅ®ĞöËãÁË¡£\n");
                return 1;
        }
        if (ob->query("class") == "taoist") {
       command("say ÎÒ¶«Ğ°×îÌÖÑáµÀÊ¿£¬¿´µ½µÀÊ¿¾ÍÓĞÆø£¡");
                return 1;
        }

        if (ob->query("age") < 20) {
                command("say Äã»¹Ğ¡£¬µÈ³¤´óÁËÔÙÀ´°É¡£\n");
                command("pat " + ob->query("id"));
                return 1;
        }
        command("say ºÃ°É£¬²»¹ıÎÒÒª³öÈıµÀÊÔÌâ¿¼¿¼Äã¡£");
        command("say µÚÒ»µÀÊÇÎä¹¦£¬µÚ¶şµÀÊÇÒôÂÉ£¬µÚÈıµÀÊÇÄ¬Ğ´¡£");
        command("say ±ØĞëÈıÕó¶¼²»Êäµô²ÅĞĞ£¡");
        command("say ÒªÊÇ×¼±¸ºÃÁË¾ÍÀ´¹ıµÚÒ»¹Ø°É£¡");
        ob->set_temp("thd_marry", 1);
        return 1;
}

int ask_test1()
{
        object ob=this_player();
        object me=this_object();
        object obj;

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") > 1) {
                command("say ÒÑ¾­¹ıÁËÕâ¹Ø»¹À´ÂŞàÂÊ²Ã´£¡");
                return 1; 
        }
        
        set("combat_exp", 2000000);
        set("jiali", 100);
        if (present("yuxiao",me))
                command("unwield yuxiao");
        prepare_skill("strike");
        prepare_skill("leg");
        prepare_skill("hand");
        prepare_skill("finger");
        prepare_skill("sword");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        say("\n»ÆÒ©Ê¦ºÈµÀ£ºµÚÒ»ÕĞÊÇÂäÓ¢Éñ½£ÕÆ£¬Ğ¡ĞÄ½ÓÕĞÁË£¡\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
          if (!present("yuxiao",me))
        if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
        else
                command("wield yuxiao");
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat Èç´Ë²»¼Ã£¬Ò²Ïë×öÎÒµÄÅ®Ğö£¿£¡");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 2500000);
                set("jiali", 120);
                return 1;
        }
        prepare_skill("strike");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        say("\n»ÆÒ©Ê¦ºÈµÀ£ºµÚ¶şÕĞÊÇÓñóï½£·¨£¬Ğ¡ĞÄ½ÓÕĞÁË£¡\n");
        if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                command("wield yuxiao");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat Èç´Ë²»¼Ã£¬Ò²Ïë×öÎÒµÄÅ®Ğö£¿£¡");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 2600000);
                set("jiali", 200);
                return 1;
        }
        if (present("yuxiao",me))
                command("unwield yuxiao");
        prepare_skill("strike");
        me->reset_action();
        prepare_skill("hand", "lanhua-shou");
        say("\n»ÆÒ©Ê¦ºÈµÀ£ºµÚÈıÕĞÊÇÀ¼»¨·÷Ñ¨ÊÖ£¬Ğ¡ĞÄ½ÓÕĞÁË£¡\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat Èç´Ë²»¼Ã£¬Ò²Ïë×öÎÒµÄÅ®Ğö£¿£¡");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 3000000);
                set("jiali", 200);
                return 1;
        }
        prepare_skill("hand");
        me->reset_action();
        prepare_skill("finger", "tanzhi-shentong");
        say("\n»ÆÒ©Ê¦ºÈµÀ£ºµÚËÄÕĞÊÇµ¯Ö¸ÉñÍ¨£¬Ğ¡ĞÄ½ÓÕĞÁË£¡\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
        else
                command("wield yuxiao");
        prepare_skill("finger");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        prepare_skill("leg", "xuanfeng-leg");
        set("combat_exp", 3200000);
        set("jiali", 200);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat Èç´Ë²»¼Ã£¬Ò²Ïë×öÎÒµÄÅ®Ğö£¿£¡");
                return 1;
        }

command("wield yuxiao");
        write("»ÆÒ©Ê¦ËµµÀ£ººÃ°É£¬ÕâµÚÒ»¹Ø¾ÍËãÄã¹ıÁË¡£\n");
        write("»ÆÒ©Ê¦ËµµÀ£ºÄãÒªÊÇ×¼±¸ºÃÁË¾ÍÀ´¹ıµÚ¶ş¹Ø°É£¡\n");
        tell_room(environment(ob), "»ÆÒ©Ê¦¶Ô" + ob->name() + "ËµµÀ£ººÃ°É£¬ÕâµÚÒ»¹Ø¾ÍËãÄã¹ıÁË¡£\n", ({ob}));
        ob->set_temp("thd_marry", 2);
        return 1;
}

int ask_test2()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 2) {
                say("»ÆÒ©Ê¦ºÈµÀ£ºÔõÃ´£¬Ïë×÷±×Ã´£¿£¡\n");
                return 1; 
        }
        if (ob->query_temp("thd_marry") > 2) {
                command("say ÒÑ¾­¹ıÁËÕâ¹Ø»¹À´ÂŞàÂÊ²Ã´£¡");
                return 1; 
        }
        
        command("say ËùÎ½ÎåÒô£¬³ıÁË¹¬ÉÌ½ÇáçÍâ£¬»¹ÓĞÒ»¸öÊÇÊ²Ã´£¿");
        return 1;
}

int ask_test3()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 3) {
                say("»ÆÒ©Ê¦ºÈµÀ£ºÔõÃ´£¬Ïë×÷±×Ã´£¿£¡\n");
                return 1; 
        }
        command("say ¾ÅÒõÕæ¾­ÑÔµÀ£ºÌìÖ®µÀ£¬ËğÓĞÓà¶ø²¹²»×ã£¬ÊÇ¹Ê....£¬ºóÃæµÄÈı¸ö×ÖÊÇÊ²Ã´£¿");
        return 1;
}

int ask_nvxu()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0;

        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id == ob->query("id")) {
                if (nvxu->query("death_count") < ob->query("death_count"))
                        command("say Ğ¡Å®ÏÖÔÚÈÔÈ»´ı×Ö¹ëÖĞ¡£");
                else
                        say(CYN"»ÆÒ©Ê¦Ğ¦µÀ£º" + RANK_D->query_rude(ob) + "£¬»¹²»¿ì½ĞÔÀ¸¸£¿£¡\n"NOR);
        }
        else {
                if (id) {
                        if (!(user = find_player(id))) {
                                user = new(USER_OB, id);
                                user->set_name("", ({ id }));
                                if (!user->restore()) {
                                        command("say Ğ¡Å®ÏÖÔÚÈÔÈ»´ı×Ö¹ëÖĞ¡£");
                                        destruct(user);
                                        return 1;
                                }
                                user_load = 1;
                        }
                }
                if (!id || nvxu->query("death_count") < user->query("death_count"))
                        command("say Ğ¡Å®ÏÖÔÚÈÔÈ»´ı×Ö¹ëÖĞ¡£");
                else
                        command("say ÎÒÒÑ°ÑĞ¡Å®ĞíÅä¸ø" + nvxu->query("name") + "ÎªÆŞÁË¡£");
                if (user_load) destruct(user);
        }
        return 1;
}

int do_answer(string arg)
{
        object ob = this_player();
        object nvxu;
        object obj;
    int payed;

        if (ob->query_temp("thd_marry") == 2) {
                tell_room(environment(ob), ob->name() + "ÔÚ»ÆÒ©Ê¦µÄ¶ú±ßĞ¡ÉùàÖ¹¾ÁËÒ»¾ä¡£\n", ({ob}));
                if (arg == "Óğ") {
                        if (!present("yuxiao",this_object()))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
command("wield yuxiao");
                        command("say ºÃĞ¡×Ó£¬²»´í£¬ÔÙÌıÌıÎÒµÄ¡¶±Ìº£³±ÉúÇú¡·¡£\n");
                        write("»ÆÒ©Ê¦´Ó»³ÖĞÈ¡³öÒ»Ö§Óñóï£¬·Åµ½×ì±ß´µÁËÆğÀ´¡£Äã·Â·ğÖÃÉí´óº£Ö®ÖĞ£¬º£³±ĞÚÓ¿¶øÀ´£¬ËÆºõÒª½«ÄãÍÌÃ»¡£\n");
                        write("ÔÙ³ÅµÃÒ»Õó£¬Äãµ«¾õº®¶¬¿áÊî£¬½»Ìæ¶øÀ´¡£\n");
                        ob->delete_temp("thd_marry");
                        ob->unconcious();
                        message("vision", "»ÆÒ©Ê¦º°¹ı¼¸¸öÆÍÒÛÀ´£º°ÑÕâ¸ö»èÃÔ²»ĞÑµÄ¼Ò»ï¶ªµ½º£ÀïÈ¥£¡\n", environment(ob), ob);
                        ob->move(__THD__"haitan");
                        message("vision","ºöÈ»Ò»¸ö´ó³±Ó¿ÁË¹ıÀ´£¬½«Ò»¸ö±»Ë®ÅİµÃ°ëËÀµÄ¼Ò»ï³åµ½ÁË°¶±ß¡£\n",environment(ob),ob);
                        return 1;
                }
                else
                        if (arg == "ÎÒ²»ÖªµÀ" || arg == "²»ÖªµÀ" || arg == "dunno") {
                                if (!present("yuxiao",this_object()))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
command("wield yuxiao");
                                command("sneer " + ob->query("id"));
                                command("say Õâ¶¼´ğ²»³ö£¿£¡\n");
                                write("»ÆÒ©Ê¦´Ó»³ÖĞÈ¡³öÒ»Ö§Óñóï£¬·Åµ½×ì±ß´µÁËÆğÀ´¡£ÄãÃ£È»²»ÖªËù×àÎªºÎ£¬ºúÂÒ»÷Æğ½ÚÅÄÀ´¡£\n");
                                write("»ÆÒ©Ê¦ËÆºõÊÜÁËÄãµÄÓ°Ïì£¬´µÁËÒ»»á¾Í²»ÔÙ¼ÌĞøÁË¡£\n");
                                write("»ÆÒ©Ê¦ËµµÀ£ººÃ°É£¬ÕâµÚ¶ş¹Ø¾ÍËãÊÇ¸öÆ½ÊÖ¡£\n");
                                write("»ÆÒ©Ê¦ËµµÀ£ºÄãÒªÊÇ×¼±¸ºÃÁË¾ÍÀ´¹ıµÚÈı¹Ø°É£¡\n");
                                tell_room(environment(ob), "»ÆÒ©Ê¦¶Ô" + ob->name() + "Ëµµ
µÀ£ººÃ°É£¬ÕâµÚ¶ş¹Ø¾ÍËãÊÇ¸öÆ½ÊÖ¡£\n", ({ob}));
                                ob->set_temp("thd_marry", 3);
                                return 1;
                        }
                say("»ÆÒ©Ê¦Å­µÀ£º²»¶Ô£¡\n");
                return 1;
        }
        if (ob->query_temp("thd_marry") == 3)  {
                say(ob->name() + "ÔÚ»ÆÒ©Ê¦µÄ¶ú±ßĞ¡ÉùàÖ¹¾ÁËÒ»¾ä¡£\n");
                if (arg == "ĞéÊ¤Êµ") {
                        command("chat* Ì§Í·ÍûÌì£¬à«à«ËµµÀ£º¡°°¢ºâ£¬°¢ºâ£¬Äã¶ÔÎÒÈç´ËÇéÖØ£¬½èÕâÉÙÄêÖ®¿ÚÀ´°ÑÕæ¾­ÊÚÎÒ£¬ÔõÃ´²»ÈÃÎÒ¼ûÄãÒ»Ãæ£¿ÎÒÍíÍí´µóï¸øÄãÌı£¬Äã¿ÉÌı¼ûÃ´£¡¡±");
                        write("»ÆÒ©Ê¦ËµµÀ£ººÃ°É£¬ÕâµÚÈı¹Ø¾ÍËãÄã¹ıÁË¡£\n");
                        tell_room(environment(ob), "»ÆÒ©Ê¦¶Ô" + ob->name() + "ËµµÀ£ººÃ°É£¬ÕâµÚÈı¹Ø¾ÍËãÄã¹ıÁË¡£\n", ({ob}));
                        write("»ÆÒ©Ê¦Ğ¦ÃĞÃĞµØ¿´×ÅÄã£¬·Â·ğÔÚÆÚ´ıÊ²Ã´¡£\n");
                        write("ÄãµÇÊ±ĞÑÎò£¬¹òÏÂÀ´¶Ô×Å»ÆÒ©Ê¦¹§¹§¾´¾´µØ¿ÄÁËÈı¸öÍ·£¬º°ÁËÉù£º¡°ÔÀ¸¸¡±£¡\n");
                        tell_room(environment(ob), ob->name() + "¹òÏÂÀ´¶Ô×Å»ÆÒ©Ê¦¹§¹§¾´¾´µØ¿ÄÁËÈı¸öÍ·£¬º°ÁËÉù£º¡°ÔÀ¸¸¡±£¡\n", ({ob}));
                        command("chat ´Ó½ñÌìÆğ£¬" + ob->name() + "¾ÍÊÇÎÒ»ÆÒ©Ê¦µÄÅ®ĞöÁË£¡");
                        payed = 0;
                        if (!ob->query("benefit/yaoshi") && !payed) {
                                write("»ÆÒ©Ê¦ËµµÀ£ºĞ¡ĞÖµÜÄÜ×öµÃÎÒµÄÅ®Ğö£¬ÀÏ·òÎŞÒÔÎªÔù£¬¾Í¸øÄã½²Ğ©ÎäÑ§µÄ¸ßÉîµÀÀí°É¡£\n");
                                write("ÄãÌı×Å»ÆÒ©Ê¦µÄ½²½â£¬ÓëĞÄÖĞËùÖªµÄÒ»¼ÓÓ¡Ö¤£¬µÇÊ±ÁìÎòÁËĞí¶àµÄÎäÑ§µÀÀí£¡\n");
                                if (ob->query("family/family_name") == "ÌÒ»¨µº")
                                        ob->add("combat_exp", 18000);
                                else
                                        ob->add("combat_exp", 15000);
                                ob->set("benefit/yaoshi", 1);
                                payed = 1;
                        }
//                        write("»ÆÒ©Ê¦ËµµÀ£ºÄãÒÑ¾­¹»×Ê¸ñ¸úÎÒÑ§Ï°À¼»¨·÷Ñ¨ÊÖÁË£¬Õâ±¾Í¼½âËÍ¸øÄã¡£\n");
//                        new(__THD__"obj/shoufa.c")->move(ob);
                        ob->delete_temp("thd_marry");
                        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                                nvxu = load_object("/clone/npc/huang-son-in-law");
                        nvxu->do_copy(nvxu, ob);
                        return 1;
                }
                say("»ÆÒ©Ê¦Å­µÀ£º²»¶Ô£¡\n");
                return 1;
        }
        return 0;
}
void unconcious()
{
        command("chat* ³¤Ì¾Ò»Éù£ºÎÒ×İºá½­ºş¼¸Ê®ÔØ£¬ÈËÈËÌıµ½¶«Ğ°¶¼ÎÅÃûÉ¥µ¨£¬Ã»Ïëµ½Ò²ÓĞ½ñÌì£¡");
        ::unconcious();
}
