#include <ansi.h>
int do_walk();
inherit NPC;
string  ask_job();
string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��", }); 
string *name_words = ({ "һ","��","��","��","��","��","��","��","��","ʮ", });
string *color_title = ({"[��ɱ��]ɱ��","[��ɷ��]ɱ��",});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["name":"�ٱ�",	"id":"guan bing",	"mw":-1,"weapon":"gangdao",]),
(["name":"���",	"id":"yu fu",	"mw":-1,]),
(["name":"�к�",	"id":"boy",	"mw":-1,]),
(["name":"Ů��",	"id":"girl",	"mw":1,]),
(["name":"��С��",	"id":"xiao er",	"mw":-1,]),
(["name":"Ա��",	"id":"yuanwai",	"mw":-1,]),
(["name":"���",	"id":"ge ji",	"mw":1,]),					
(["name":"�ܼ�",	"id":"guan jia",	"mw":-1,]),
(["name":"�깫",	"id":"gui gong",	"mw":-1,]),
(["name":"����",	"id":"hong niang",	"mw":1,]),
(["name":"С���",	"id":"xiao hunhun",	"mw":-1,]),
(["name":"��ɮ",	"id":"huogong seng",	"mw":-1,]),
(["name":"���",	"id":"huoji",	"mw":-1,]),
(["name":"����ɮ",	"id":"kanmen seng",	"mw":-1,]),
(["name":"����Ů��",	"id":"girl",	"mw":1,]),
(["name":"̤����Ů",	"id":"girl",	"mw":1,]),
(["name":"����Ů��",	"id":"girl",	"mw":1,]),
(["name":"СѾͷ",	"id":"littlegirl",	"mw":1,]),											
(["name":"��ͯ",	"id":"ma tong",	"mw":-1,]),
(["name":"������ͷ",	"id":"lao tou",	"mw":-1,]),		
(["name":"������",	"id":"lao popo",	"mw":1,]),		
(["name":"ǩ��",	"id":"qian ke",	"mw":-1,]),		
(["name":"����С��",	"id":"tang fan",	"mw":-1,]),				
(["name":"�ò�",	"id":"ya chai",	"mw":-1,]),		
(["name":"ɽ��",	"id":"shan zei",	"mw":-1,]),		
(["name":"��ʦ",	"id":"chu shi",	"mw":-1,]),		
(["name":"�����",	"id":"fu ren",	"mw":1,]),		
(["name":"Ů���",	"id":"guan jia",	"mw":1,]),				
(["name":"����",	"id":"lama",	"mw":-1,]),		
(["name":"������",	"id":"lama",	"mw":-1,]),		
(["name":"����",	"id":"pu yi",	"mw":-1,]),		
(["name":"��ǰ����",	"id":"shi wei",	"mw":-1,	"weapon":"gangdao",]),		
(["name":"����Ӫ����",	"id":"shi wei",	"mw":-1,	"weapon":"gangdao",]),				
(["name":"����",	"id":"tiejiang",	"mw":-1,]),		
(["name":"��ؤ",	"id":"qi gai",	"mw":-1,]),			
(["name":"Ů��ؤ",	"id":"nvqi gai",	"mw":1,]),			
(["name":"��ʿ",	"id":"dao shi",	"mw":-1,]),			
(["name":"Ů��ʿ",	"id":"nv daoshi",	"mw":1,]),
(["name":"Ϸ��",	"id":"xi zi",	"mw":1,]),		
(["name":"Ѿ��",	"id":"ya huan",	"mw":1,]),	
(["name":"԰��",	"id":"yuan ding",	"mw":-1,]),	
(["name":"�ƹ�",	"id":"zhanggui",	"mw":-1,]),	
(["name":"�ɲ�Ů",	"id":"cha girl",	"mw":-1,]),	
(["name":"����ʦ",	"id":"old chanshi",	"mw":-1,]),	
(["name":"����",	"id":"dao ke",	"mw":-1,]),	
(["name":"�����",	"id":"jinxiang ke",	"mw":-1,]),	
(["name":"�컨����",	"id":"hong hua",	"mw":-1,]),	
(["name":"����",	"id":"jian ke",	"mw":-1,]),	
(["name":"���",	"id":"ma fu",	"mw":-1,]),	
(["name":"ý��",	"id":"mei po",	"mw":-1,]),		
(["name":"������",	"id":"mengmianren",	"mw":-1,]),			
(["name":"�",	"id":"poor man",	"mw":-1,]),				
(["name":"����",	"id":"shu sheng",	"mw":-1,]),				
(["name":"�Ϻ���",	"id":"lao heshang",	"mw":-1,]),				
(["name":"Сɳ��",	"id":"xiao shami",	"mw":-1,]),				
(["name":"����",	"id":"tiao fu",	"mw":-1,]),							
(["name":"�ο�",	"id":"youke",	"mw":-1,]),				
(["name":"���Ӹ�",	"id":"gongzi",	"mw":-1,]),				
(["name":"�Ů",	"id":"bi nu",	"mw":1,]),				
(["name":"���",	"id":"ni gu",	"mw":1,]),							
(["name":"С��",	"id":"xiao fan",	"mw":-1,]),			
(["name":"��Ů",	"id":"ji nv",	"mw":1,]),	
(["name":"�ϸ���",	"id":"fu zi",	"mw":1,]),	
(["name":"��ͷ",	"id":"bu tou",	"mw":-1,	]),
(["name":"�첶",	"id":"kuai bu",	"mw":-1,	]),
(["name":"����",	"id":"tie bu",	"mw":-1,	]),
(["name":"����",	"id":"ya yi",	"mw":-1,	]),
(["name":"����",	"id":"gong gong",	"mw":-1,	]),
(["name":"����",	"id":"pao tang",	"mw":-1,	]),
(["name":"�ŷ�",	"id":"jiao fu",	"mw":-1,	]),
(["name":"�÷�",	"id":"cai feng",	"mw":-1,	]),
(["name":"ҩʦ",	"id":"yao shi",	"mw":-1,	]),
(["name":"�ٲ�",	"id":"guan cha",	"mw":-1,	]),
(["name":"�佫",	"id":"wu jiang",	"mw":-1,	]),
(["name":"ɽ��ͷ",	"id":"shan zeitou",	"mw":-1,	]),
(["name":"�͵���",	"id":"huo ji",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"����",	"id":"shi wei",	"mw":-1,	"weapon":"changqiang",	]),
(["name":"����",	"id":"tie jiang",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"��åͷ",	"id":"liumang tou",	"mw":-1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"gui gongzi",		"mw":-1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"xing ze",	"mw":-1,	"weapon":"gangdao",]),
(["name":"����ͷ",	"id":"tufei tou",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ϸ��",		"id":"xi zi",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨���̷�",	"id":"shang fan",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��������",	"id":"yi ren",	"mw":-1,	"weapon":"gangjian",]),
(["name":"������",	"id":"kanzu ren",	"mw":-1,	"weapon":"changbian",	]),
(["name":"����",		"id":"lie ren",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨������",	"id":"old lieren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"������",	"id":"muyang ren",	"mw":-1,	"weapon":"gangjian",]),
(["name":"ũ��",	"id":"nong fu",	"mw":-1,	"weapon":"gangjian",]),
(["name":"Ƥ����",	"id":"pihuo sang",	"mw":-1,	"weapon":"changbian",	]),
(["name":"ʯ��",		"id":"shi jiang",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"dao ren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"�ο�",	"id":"you ke",	"mw":-1,	"weapon":"gangjian",]),
(["name":"��ͯ",	"id":"shu tong",	"mw":1,	"weapon":"gangjian",]),
(["name":"��Ӫ����",	"id":"guan bing",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ա��",		"id":"yuan wai",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"bi qiu",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��å",	"id":"liu mang",	"mw":-1,	"weapon":"gangjian",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",300000);
	if( weapon)	set_skill("blade",20);
	set_skill("unarmed",20);
        set("tasknpc",1);
        set("dex",200);
        set("no_get",1);
	set_skill("sword",120);
	set_skill("club",120);
	set_skill("whip",120);
	set_skill("throwing",120);
	set_skill("parry",120);
set("qi",8000);
set("jing",8000);
set("eff_qi",8000);
set("eff_jing",10000);
set("max_qi",8000);
set("max_jing",15000);
set("per",16+random(20));
	set_skill("dodge",300);
	set("shen_type",npc["mw"]);
if (npc["mw"]=1) set("gender", "Ů��");
        set("chat_chance", 50);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 80);
	set_skill("tiyunzong", 80);
	set_skill("unarmed", 80);
	set_skill("taiji-quan", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("array",80);
	set_skill("blade", 80);
	set_skill("shiren-jianfa", 180);
	set_skill("shiren-quanfa", 280);
	set_skill("wuxing-dun", 80);
	map_skill("unarmed", "shiren-quanfa");
	map_skill("parry", "shiren-jianfa");
	map_skill("blade", "shiren-jianfa");
	map_skill("dodge", "wuxing-dun");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
           (: random_move :),
           (: random_move :),
           (: random_move :),
        }) );
        set("inquiry", ([
   	    "����"  : (: ask_job :),
	    "task"  : (: ask_job :),
            ]));

        set_temp("apply/attack", 30);
        set_temp("apply/defense",150);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 160+random(80));
        setup();
        set("check_time", time());
	carry_object("/clone/cloth/cloth")->wear();
//	if( weapon)
 	carry_object("/quest/weiguo/japan/obj/japanblade")->wield();

	carry_object("/d/feitian/npc/obj/wushidao")->wield();
if (random(8)==0)	carry_object("/clone/misc/ybook");
	add_money("silver",50+random(50));
}
       
int do_walk()
{
        string start_room;
 string name,weapon;
        object room;
        object ob;
        mapping obmap;
        int n;
        int i;
	object *inv;
        if (! environment())
                return 0;
        name = color_title[random(sizeof(color_title))]+first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
//1800
//        if (time() - query("check_time") > 3600)
      if (time() - query("check_time") > 3000 && random(100)>98 || !query_heart_beat(this_object()))
        {
       set_name((order[random(13)])+name, ({ "killer", "shashou", "sha shou" }));
       set("gender", "����");
       set("title", color_title[random(sizeof(color_title))]);
        n = 0;
	inv = all_inventory(this_object());

	for (i = 0; i < sizeof(inv); i++)
        {
                if (inv[i]->query("dynamic_quest"))
command("chat "+inv[i]->query("name")+(order[random(13)])+"���Ѿ��õ����ˡ�������!!  \n"NOR);
        }

                        message_vision("$NЦ��Ц˵�������Ѿ����֣�������ɣ����ˣ�\n"NOR, this_object());
                        destruct(this_object());
                        return 0;
        }

        n = 0;
        foreach (ob in all_inventory(environment()))
        {
                if (!ob)  continue;
                if (!ob->query("dynamic_quest"))
                        continue;
        command ("get all");
                n++;
        }

                        
        random_move();
        return 1;
}

int accept_fight(object ob)
{
				command("say " + RANK_D->query_self(this_object())
					+ "��ô������" + RANK_D->query_respect(ob)
					+ "�Ķ��֣�\n");
		  return 0;
}

int kill_ob(object ob)
{
        string start_room;
 string name,weapon;
        object room;
        mapping obmap;
        int n;
        int i;
	object *inv;
        name = color_title[random(sizeof(color_title))]+first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
		  command("fear");
		  command("say ���ã��ұ�ʶ����!!");
if (random(3)==1)
{
command("say �Ӱ�!!");
if (random(2)==1)
{
command("go south");
command("go south");
command("go south");
command("go west");
command("go west");
command("go northup");
command("go southup");
command("go eastup");
command("go westup");
command("go northdown");
command("go southdown");
command("go eastdown");
command("go westdown");
command("go northeast");
command("go northwest");
command("go southeast");
command("go southwest");
command("go north");
command("go east");
}
else
{
command("go north");
command("go north");
command("go north");
command("go east");
command("go east");
command("go north");
command("go northup");
command("go southup");
command("go eastup");
command("go westup");
command("go northdown");
command("go southdown");
command("go eastdown");
command("go westdown");
command("go northeast");
command("go northwest");
command("go southeast");
command("go southwest");
command("go south");
command("go west");

}
}
else if ((ob->query("combat_exp") > 2500000 && random(3)==1) || random(66)==0)
{
command("say ���Ӻ���ƴ��!!");
set("qi",20000);
set("jing",20000);
set("eff_qi",20000);
set("eff_jing",20000);
set("max_qi",20000);
set("max_jing",25000);
  set_name((order[random(13)])+name+NOR, ({ "killer", "shashou", "sha shou" }));
       set("gender", "����");

	set("neili", 28000);
	set("max_neili", 28000);

	set("combat_exp", 2500000+random(250000));
	set_skill("unarmed",220);
	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("sword", 220);
	set_skill("staff", 220);
	set_skill("literate", 220);
	set_skill("huashan-zhangfa", 220);
	set_skill("huashan-shenfa",220);
	set_skill("huashan-jianfa", 220);
	set_skill("zixia-shengong", 220);
	set_skill("shenlong-xinfa", 220);
	set_skill("shedao-qigong", 220);
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.feilong" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: perform_action, "sword.jm" :),
                (: random_move :),
        }) );
}
else if (ob->query("combat_exp") > 5000000 && random(3)==1
)
{
command("say ȥ����!!");
set("qi",38000);
set("jing",38000);
set("eff_qi",30000);
set("eff_jing",30000);
set("max_qi",30000);
set("max_jing",30000);
  set_name((order[random(13)])+name+NOR, ({ "killer", "shashou", "sha shou" }));
       set("gender", "����");

	set("neili", 38000);
	set("max_neili", 38000);

	set("combat_exp", 5000000);
       set_skill("dodge",300);
        set_skill("cuff",300);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",320);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",300);
        set_skill("shayi",300);
         set_skill("aikido",300);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",300);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
	map_skill("unarmed", "shiren-quanfa");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
                (: random_move :),
        }));
if ((ob->query("combat_exp") > 10000000
|| ob->query_skill("jiuyin-zhengong",1) >400) && random(3)==1)
{
set("qi",42000);
set("jing",42000);
set("eff_qi",42000);
set("eff_jing",40000);
set("max_qi",40000);
set("max_jing",40000);
	set("neili", 58000);
	set("max_neili", 58000);

	set("combat_exp", 10000000);

       set_skill("dodge",400);
        set_skill("cuff",400);
        set_skill("unarmed",400);
        set_skill("parry",400);
        set_skill("blade",420);
         set_skill("feitian-yujianliu",450);
         set_skill("wuxing-dun",400);
        set_skill("shayi",400);
         set_skill("aikido",400);
         set_skill("shayi-xinfa",400);
        set_skill("shiren-jianfa",400);
        set_skill("shiren-quanfa",480);
        set_skill("force",400);
set_skill("huoxinliu-jianfa",400);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
	map_skill("unarmed", "shiren-quanfa");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
                (: random_move :),
        }));

}

}

}



string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
 if (!environment(guo)->query("no_fight"))
return  "������ʲô��?";
 if (environment(guo)->query("no_fight"))
{
command("say �Ӱ�!!");
if (random(2)==1)
{
random_move();
        set("chat_chance", 90);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

}
else
{

random_move();
        set("chat_chance", 90);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

}
}
return  "�����˶࣬����ȫ������!";
}

int hit_ob(object me, object ob, int damage)
{
string msg;
        if(random((int)me->query("combat_exp")) > random((int)ob->query("combat_exp")) || random(4)==1)   
{
             ob->add("qi",-ob->query("qi")/30);
             ob->add("eff_qi",-ob->query("eff_qi")/30);
             ob->add("jing",-ob->query("jing")/30);
             ob->add("eff_jing",-ob->query("eff_jing")/30);
         ob->apply_condition("ice_poison", 10);
        ob->apply_condition("ill_dongshang", 10);
        ob->apply_condition("ill_fashao", 10);
        ob->apply_condition("ill_kesou", 10);
        ob->apply_condition("ill_shanghan", 10);
        ob->apply_condition("ill_zhongshu", 10);        
        ob->apply_condition("xx_poison", 10);
        ob->apply_condition("cold_poison", 10);
        ob->apply_condition("flower_poison", 10);
if (random(6)==0)
ob->apply_condition("sanxiao_poison", 2);
}
           msg = HIR"$N"HIR"��Цһ��,������һ�����ҩ,"HIR"$n"HIR"���Ե�������������!!\n"NOR;
            message_vision(msg, me, ob);

}