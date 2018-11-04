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
              obj->set("long", RED+"一杯醇正的" + nmstr + "。\n" + NOR);
        obj->set("liquid/name", nmstr);
write( HIG "酒:"+nmstr+HIG"做好了。"+"\n" NOR);
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
              obj->set("long", YEL+"一杯可口的" + nmstr + "。\n" + NOR);
        obj->set("liquid/name", nmstr);
write( HIG "荼:"+nmstr+HIG"买好了。"+"\n" NOR);
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
              obj->set("long", GRN+"一盘热气腾腾, 香喷喷的"+nmstr+"。\n"+NOR);
write( HIG "菜:"+obj->query("name")+HIG"做好了。"+"\n" NOR);
        obj->move(me);
}
void create()
{
        set_name(HIW"宝儿"NOR, ({ "shi tong",  "shitong"}));
	set("title", HIM "绝世风华" NOR);
	set("long", HIG "他看上去只有十来岁，长得正是玉树临风，潇洒倜傥。\n"+
	"但他的双目中却包含着一种深深的忧郁，\n"+
	"似乎正在感叹人间沧桑，世事无常。\n" NOR);
        set("marry","hxsd");
        set("gender", "男性");
 	set("age", 18);
        set("str", 50);
        set("cor", 50);
        set("baohu","hxsd");
        set("couple/couple_name","小人物");
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
        set_skill("yunv-xinfa", 400);    //玉女心法
        set_skill("sword", 400);
        set_skill("yunv-jian", 400);     //玉女剑
        set_skill("quanzhen-jian",400);  //全真剑
        set_skill("dodge", 400);
        set_skill("yunv-shenfa", 400);   //玉女身法
        set_skill("parry", 400);
        set_skill("hubo", 400);          //双手互搏
        set_skill("unarmed",400);
        set_skill("meinv-quan", 400);    //美女拳法
        set_skill("literate",400);
        set_skill("qufeng",400);         //驱蜂之术
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
		(: command, "emote 眨了眨眼道：我们差不多该上路了吧，好吗！" :),
                (:random_chat:),
             (:random_chat:),
             (:random_chat:),
             (:random_chat:),             	             	
        }) );

	set("inquiry", ([
		"走" : (: ask_go :),
		"亲热" :  (: ask_kiss :),
		"等待" :  (: ask_wait :),
		"回家" :  (: ask_home :),
		"做饭" :  (: ask_eat :),
		"普通攻击" :  (: ask_fight :),
		"一般攻击" :  (: ask_fight1 :),
		"全力攻击" :  (: ask_fight2 :),
		"牵制攻击" :  (: ask_fight3 :),
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
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

        if(me->is_busy())
{
command("say 主人，你太忙了，我帮不上你！");
        return notify_fail("你上一个动作还没有完成。\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
	   if(random(10)>7)	          
           {
	   say(query("name")+"满脸羞得通红，垂下头来，缓缓的点了点头。\n");
           command("lovelook "+ me->query("id") );
           command("cat "+ me->query("id") );
           command("kiss "+ me->query("id") );
           write(CYN"你对"+query("name")+CYN"微微一笑，流露出无限的喜爱之情。\n"NOR);
           write(CYN" "+query("name")+CYN"深深的注视着你，双目蕴涵着浓浓的爱意。\n"NOR);
           command("makelove "+ me->query("id") );
           me->start_busy(1);
           this_object()->start_busy(1);
           }		
           else 
{
	   me->start_busy(1);
           this_object()->start_busy(1);
	   say(query("name")+"啊的一声，一下子跳将开去，说：不行，不可以。\n");
	   return 1;
}
           }
//	}
//else say(query("name")+"说道：呸，我不干。");
return 1;
}

int ask_go()
{
  object me;
  string new_name,new_id,host_id;
   me=this_player();
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

//	   if(query("id")!="bao er")
//        {
//		 sscanf(query("id"),"%s's bao er",host_id);
		 if(query("id")==query("host_id"))
           {say(query("name")+"睁大眼睛看了看"+
				me->query("name")+"，说：当然愿意啦，我都听你的。\n");
            return 1;
           }
	 if(me->query("id")!=query("host_id"))
           {say(query("name")+"睁大眼睛看了看"+
				me->query("name")+"，说：不行的，我得听我主人的。\n");
			return 1;
           }
//	 }
	   command("nod");
	   command("say 主人待我恩重如山，我一定会尽心尽力的服侍你！");
           set_leader(me);
return 1;
}

int ask_wait()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

        if(me->is_busy())
{
command("say 主人，你太忙了，我帮不上你！");
        return notify_fail("你上一个动作还没有完成。\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
           command("inn " + me->query("id"));
           command("say 我暂时在这里等你，如果有什么事，记得召唤我哦！");
           set_leader(0);
	   return 1;
           }
//	}
//say(query("name")+"说道:你是谁？我又不认识你，就不听你的！");
return 1;
}

int ask_home()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
	if (this_object()->is_busy())
		return notify_fail("现在正忙着呢。\n");
	if( this_object()->is_fighting() )
		return notify_fail("已经在战斗中了，学一点实战经验吧。\n");

	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

        if(me->is_busy())
{
command("say 主人，你太忙了，我帮不上你！");
        return notify_fail("你上一个动作还没有完成。\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
	if (is_busy() || is_fighting()) {
		command("say 我正忙着，等一会再回去。");
		return 1;
	}
	   if(random(10)>3)	          
           {
	   message("vision",
		 name() + "说道：主人如再要我服待，请发哨为警！我等你啊！\n\n"
		+ name() + "闪了闪就消失不见了。\n" , environment(),
		this_object() );
	   destruct(this_object());
           }		
           else 
	   say(query("name")+"啊的一声,轻声细语的说:求求"+me->query("name")+"主人,不要.我不要回家\n");
	   return 1;
           }
//	}
//say(query("name")+"说道:你是谁？我又不认识你，就不听你的！");
return 1;
}

int ask_fight()
{
  object me;
  string new_name,new_id;
  me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

        if(me->is_busy())
{
command("say 主人，你太忙了，我帮不上你！");
        return notify_fail("你上一个动作还没有完成。\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say 好的，我尽量小心，不出绝招了！");
           change_combat_mode(me, 0);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" 我不认识你啊？");
return 1;
}

int ask_fight1()
{
  object me;
  string new_name,new_id;
  me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

        if(me->is_busy())
{
command("say 主人，你太忙了，我帮不上你！");
        return notify_fail("你上一个动作还没有完成。\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say 下次战斗我一定小心出招！");
           change_combat_mode(me, 1);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" 我不认识你啊？");
return 1;
}

int ask_fight2()
{
  object me;
  string new_name,new_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

        if(me->is_busy())
{
command("say 主人，你太忙了，我帮不上你！");
        return notify_fail("你上一个动作还没有完成。\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say 下次战斗我一定尽我的全力攻击对手！");
           change_combat_mode(me, 2);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" 我不认识你啊？");
return 1;
}

int ask_fight3()
{
  object me;
  string new_name,new_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

        if(me->is_busy())
{
command("say 主人，你太忙了，我帮不上你！");
        return notify_fail("你上一个动作还没有完成。\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say 下次战斗我一定尽我的全力牵制对手！");
           change_combat_mode(me, 3);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" 我不认识你啊？");
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
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

        if(me->is_busy())
{
command("say 主人，你太忙了，我帮不上你！");
        return notify_fail("你上一个动作还没有完成。\n");
return 1;
}

        obs = filter_array(all_inventory(me), (: ! $1->query("equipped") :));
        if (sizeof(obs) >= 38            )
{
write( CYN "你身上的东西实在是太多了，没法再拿吃的东西了。"+"\n" NOR);
                return notify_fail("你身上的东西实在是太多了，没法再拿吃的东西了。\n");
}
if (inv)
{
		sizeinv=sizeof(inv);
		while (sizeinv--)
		{
       			if (inv[sizeinv]->query("guardfood"))
{
write( CYN "你身上还有吃的东西没吃完呢"+"\n" NOR);
     				return notify_fail("你身上不还有吃的吗？\n");
}    		
		}
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
me = this_player();
message_vision("$N拿出了一些做饭材料，升起了火，为主人$n做起饭来．．．\n",this_object(),me);
       write( CYN ".................."+"\n" NOR);
       write( CYN "..............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN "........."+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "."+"\n" NOR);
       write( CYN " "+query("name")+"把做完的饭装在几个盘子里给了你。"+"\n" NOR);
       write( CYN " "+query("name")+"从怀中拿出几个冷馒头，站在你旁边吃了起来。"+"\n" NOR);
me->start_busy(6);
this_object()->start_busy(6);
            set ("food",170);
            set ("water",170);
if (random(30)>25)
create_water(HIW"羊奶"NOR, ({ "milk" }), CYN"青花碗"NOR );
else if (random(30)>20)
create_water(GRN"云雾茶"NOR, ({ "tea" }), MAG"紫砂茶盅"NOR );
else if (random(30)>20)
create_water(GRN"碧螺春"NOR, ({ "tea" }), MAG"紫砂盏"NOR );
else if (random(30)>20)
create_water(HIG"君山银针"NOR, ({ "tea" }), RED"红泥盏"NOR );
else if (random(30)>20)
create_water(HIR"红毛尖"NOR, ({ "tea" }), CYN"青泥盏"NOR );
else if (random(30)>20)
create_water(GRN"云雾茶"NOR, ({ "tea" }), MAG"紫砂茶盅"NOR );
else if (random(30)>20)
create_water(HIG"龙井茶"NOR, ({ "tea" }), MAG"紫砂茶盅"NOR );
else if (random(30)>20)
create_water(RED"普洱茶"NOR, ({ "tea" }), WHT"水晶盏"NOR );
else if (random(30)>20)
create_water(HIG"君山银针"NOR, ({ "tea" }), RED"红泥盏"NOR );
else 
create_water(HIW"鲜奶"NOR, ({ "milk" }), WHT"玻璃杯"NOR );
if (random(30)>25)
                create_wine(HIW"汾酒"NOR, ({ "wine" }), WHT"羊脂白玉杯"NOR );
else if (random(30)>20)
                create_wine(WHT"关外白酒"NOR, ({ "wine" }), YEL"犀角杯"NOR );
else if (random(30)>20)
                create_wine(RED"葡萄酒"NOR, ({ "wine" }), HIW"夜光杯"NOR );
else if (random(30)>20)
                create_wine(WHT"高粱酒"NOR, ({ "wine" }), CYN"青铜爵"NOR );
 else if (random(30)>20)
                create_wine(HIG"百草酒"NOR, ({ "wine" }), RED"古藤杯"NOR );
else if (random(30)>20)
                 create_wine(HIR"状元红"NOR, ({ "wine" }), WHT"古瓷杯"NOR );
else if (random(30)>20)
                 create_wine(GRN"梨花酒"NOR, ({ "wine" }), HIG"翡翠杯"NOR );
else if (random(30)>20)
                 create_wine(HIW"玉露酒"NOR, ({ "wine" }), WHT"琉璃杯"NOR );
else if (random(30)>20)
                 create_wine(RED"陈年花雕"NOR, ({ "wine" }), HIW"宋瓷杯"NOR  );
else if (random(30)>20)
                 create_wine(WHT"五粮液"NOR, ({ "wine" }), WHT"玻璃杯"NOR );
else if (random(30)>20)
                 create_wine(WHT"米酒"NOR, ({ "wine" }), HIW"搪瓷杯"NOR );
else if (random(30)>20)
                 create_wine(HIR"杜康酒"NOR, ({ "wine" }), HIG"青铜爵"NOR  );
else if (random(30)>20)
                 create_wine(HIW"透瓶香"NOR, ({ "wine" }), WHT"琉璃杯"NOR  );
else if (random(30)>20)
                 create_wine(WHT"米酒"NOR, ({ "wine" }), HIW"搪瓷杯"NOR );
else if (random(30)>20)
                 create_wine(GRN"竹叶青"NOR, ({ "wine" }), GRN"翡翠杯"NOR );
else if (random(30)>20)
                 create_wine(YEL"绍兴黄酒"NOR, ({ "wine" }), HIY"象牙杯"NOR );
else if (random(30)>20)
                 create_wine(HIR"女儿红"NOR, ({ "wine" }), MAG"紫檀杯"NOR );
else if (random(30)>20)
                 create_wine(WHT"茅台酒"NOR, ({ "wine" }), YEL"鎏金杯"NOR );
else if (random(30)>20)
                 create_wine(RED"桂花酒"NOR, ({ "wine" }), WHT"琉璃杯"NOR );
else if (random(30)>20)
                 create_food(YEL"香酥花生"NOR,({"peanut"}) );
else 

if (random(40)>35)
                create_food(HIR"酒糟红枣"NOR,({"jujube"}) );
if (random(40)>35)
                create_food(HIW"奶油瓜子"NOR,({"melon seeds","seeds"}) );
if (random(40)>35)
                create_food(HIG"碧螺春卷"NOR, ({ "spring roll","roll" }) );
if (random(40)>35)
                create_food(HIC"香片蒸鱼"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIW"麻辣手撕鸡"NOR, ({"chicken"}) );
if (random(40)>35)
                create_food(HIR"干煸尤鱼"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIY"东北水饺"NOR, ({ "dumpling" }) );
if (random(40)>35)
                create_food(RED"麻辣火锅"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIR"油煎螃蟹"NOR, ({ "crab" }) );
if (random(40)>35)
                create_food(HIY"粉蒸肉"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(YEL"家常豆腐"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(HIY"德州扒鸡"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(HIG"碧螺春卷"NOR, ({ "spring roll","roll" }) );
if (random(40)>35)
                create_food(HIC"香片蒸鱼"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(YEL"咖喱饭"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(RED"蚝油肉片"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(RED"羊肉串"NOR, ({ "mutton" }) );
if (random(40)>35)
                create_food(HIR"重庆火锅"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIY"北京烤鸭"NOR, ({ "duck" }) );
if (random(40)>35)
                create_food(YEL"粉蒸肉"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(HIW"四喜豆腐"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(YEL"叫花鸡"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(HIW"四喜豆腐"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(HIG"碧螺春卷"NOR, ({ "spring","roll" }) );
if (random(40)>35)
                create_food(HIC"香片蒸鱼"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(RED"羊肉串"NOR, ({ "mutton" }) );
if (random(40)>35)
                create_food(HIY"花枝饭卷"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(HIR"鱼香肉丝"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(HIY"德州扒鸡"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(RED"麻辣火锅"NOR, ({ "chrafing dish","dish" }) );
if (random(40)>35)
                create_food(HIY"北京烤鸭"NOR, ({ "duck" }) );
if (random(40)>35)
                create_food(HIW"白斩鸡"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(YEL"粉蒸肉"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(HIR"重庆火锅"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIR"麻婆豆腐"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(RED"蚝油肉片"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(YEL"咖喱饭"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(HIW"麻辣手撕鸡"NOR, ({"chicken"}) );
if (random(40)>35)
                create_food(HIR"干煸尤鱼"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIY"东北水饺"NOR, ({ "dumpling" }) );              return 1;
              return 1;

           }
//	}
//say(query("name")+"我恁什么为你做饭，你又不是我主人！！");
//command("kick "+ me->query("id") );
return 1;
}

int do_att(string arg)
{
  object ob; 
  string host_id;
  object me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

//  if(query("id")=="bao er")
//   {say("你无权使用此命令。\n");
//    return 0;}
// sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
  return notify_fail(" "+query("name")+"连理都不理你！\n");
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail(" "+query("name")+"傻傻地望着你，不明白你的意思。\n");
  if(!living(ob)) 
	 return notify_fail(" "+query("name")+"说:"
              +ob->query("name")+"已经这样啦你还要...？？！！\n");
// 不能杀自己
	if (userp(ob) && ob == me->query("possessed"))
		return notify_fail("你疯了，想自杀么？\n");
// 不能 pk exp < 自己的玩家 (by xbd)
	if (userp(ob) && ob->query("combat_exp") < me->query("combat_exp"))
		return notify_fail("你不能欺负比自己弱小的玩家！\n");
        if (userp(ob)
         && ob->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(ob)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");

    if(userp(ob) && ob->query_condition("nokill")
    && !ob->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");	
  message_vision(name()+"对$N点头道: 嗯，好的。\n",this_player());
command("hit "+ob->query("id"));
//  fight_ob(ob);
  return 1;
}

int do_ting()
{
   string host_id;
  object me=this_player();
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

//  if(query("id")=="bao er")
//   return notify_fail("你无权使用此命令。\n");
//  sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
   return notify_fail(" "+query("name")+"连理都不理你！\n");
 if(!is_fighting())
	 return notify_fail(" "+query("name")+"现在没和人打斗。\n");
 message_vision(" "+query("name")+"对主人$N微微一笑，跳出了战圈。\n",me);
command("halt");
return 1;
}

int do_send(string arg)
{
  object ob; string host_id,new_name,new_id;
  object me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

//  if(query("id")=="bao er")
//   return notify_fail("你无权使用此命令。\n");
//  sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
   return notify_fail(" "+query("name")+"连理都不理你！\n");
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("你要把 "+query("name")+"送给谁？\n");
  if(!living(ob)) 
	 return notify_fail("你只能把"+query("name")+"给活人!\n");
 message_vision(" "+query("name")+"眼泪汪汪地望着主人$N，说:\n主人待我好,是我命好;主人待我不好,是我命苦罢了.\n",me);
 set_leader(ob);
 new_name = ob->query("name")+"的丫环"+query("name")+" ";
	   set("long","这是"+new_name+"。\n"
		"他是一个清纯绝俗的少女,大约十八,九岁年纪;\n"
	            "他长得极美，尤其是那双眼睛，清纯得像一潭碧水。\n"+
	            "其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。\n"+
		"一张雪白的脸庞,眉弯嘴小,却象是刚受人欺负,眼泪汪汪地看着你。\n");
 new_id=ob->query("id")+"'s bao er�";
           set("possessed",ob);
           set("host_id",ob->query("id"));
 set("name",new_name);
 set("id",new_id);
 write( HIY " "+query("name")+HIY"对新主人"+ob->query("name")+"楚楚可怜地盈盈一拜。\n" NOR);
write( "可用指令:\natt sb 攻击某人.\nsha sb 杀死某人.\nting 停止战斗.
sendto sb.--把"+query("name")+"送给sb.
hulian skill 互练某武功.
taolun skill 讨论某武功.
mache  splace叫马车去某地.
heji   sb    合击某人.
shape  id    看状态.\n");

 return 1;
}

int do_sha(string arg)
{
        int i ;
	object me,ob;
	object* obj;
	me = this_object();
if (this_object()->is_busy())
return notify_fail("他正忙着呢！\n");
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

        if(this_player()->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

        if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("你要"+query("name")+"杀谁？\n");
	if(!environment(ob)->query("no_fight"))
	{
// 不能杀自己
	if (userp(ob) && ob == me->query("possessed"))
		return notify_fail("你疯了，想自杀么？\n");
// 不能 pk exp < 自己的玩家 (by xbd)
	if (userp(ob) && ob->query("combat_exp") < me->query("combat_exp"))
		return notify_fail("你不能欺负比自己弱小的玩家！\n");
        if (userp(ob)
         && ob->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(ob)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");

    if(userp(ob) && ob->query_condition("nokill")
    && !ob->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");	
        message_vision(name()+"对$N点头说道: 嗯，好的。\n",this_player());
	command("say 哼，主人要我杀了你！");
        command("hit " + ob->query("id"));
	}
	return 1;
}       

void kill_ob(object ob)
{
if (ob->query("id")==query("host_id"))
{
command("say 我对主人尽心尽力,但主人你为什么要杀我啊！");	
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
        command("say " + me->name() + "，你想做什么！不要伤我主人！");
        command("emote 闪身挡在你的面前！");
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
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (me->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");
if (this_object()->is_busy())
return notify_fail("他正忙着呢！\n");

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( (int)me->query("qi") < 50 )
		return notify_fail("你没有那么多的气！\n");

	if( (int)me->query("jing") < 50 )
		return notify_fail("你现在精不够！\n");

        if (where->query("sleep_room"))
                return notify_fail("卧室不能互练，会影响别人休息。\n");
if( environment(me)->query("outdoors") ) 
          return notify_fail(HIY"\n不要影响别人，还是找一个室内的地方吧。\n"NOR);

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if( !arg ) 
		return notify_fail("你要互练什么武功啊。\n");


	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("指令格式：practice|lian <技能种类> <次数>\n");

	if ( times < 1 || times > 10)
		return notify_fail("互练次数必须大于一次，但不能超过十次。\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");


	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	notify_fail("你现在不能练习这项技能。\n");

	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
		return notify_fail("也许是缺乏实战经验，你的练习总没法进步。\n");

	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");

	write( HIW "你与"+query("name")+"把" + to_chinese(skillname) + HIW"互练了"+chinese_number(times)+"趟。\n" NOR);
	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
	{
                me->start_busy(1);
		return notify_fail("也许是缺乏实战经验，你的练习总没法进步。\n");
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
	write( HIY "你的" + to_chinese(skillname) + "进步了！\n" NOR);
	return 1;
}

void destroying(object ob)
{   
object me=this_player();
command("say 主人你要杀我，不劳您动手。。。\n");
command("say 我的命真苦。。。\n");
command("say "+me->query("name")+"主人以后我不能继续再服待你了。。。\n");
command("say 大家珍重。。。\n");
command("say 珍重。。。\n");
message_vision("$N说罢，拿起剑自刎而死，他缓缓的到在地上。。。\n",this_object());
this_object()->die();
   return;      
}

int do_move(string arg)
{

          string pla;
          object me = this_player();
	if( !living(this_object()) )
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");
if (this_object()->is_busy())
return notify_fail("他正忙着呢！\n");
if (this_player()->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");

if( me->query("jing") < 50 )
               return notify_fail("你身体不太好，做马车加出事的！\n");
if( me->is_busy())
return notify_fail("你现在在正忙着呢！\n");

if( !environment(me)->query("no_fight"))
{
  message_vision("只有在安全的地方才能叫马车！\n"
                 ,me);
      	return 1;
}
if (!arg)
return notify_fail("你想去哪里呢？\n");
if( !wizardp(me) && me->is_fighting()  ) 
 return notify_fail("你在和别人打架，没空叫马车吧？\n");
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
"马车不到那个地方啊！\n"NOR, me);
               message_vision(HIY
"车行里可以去的地方有如下：
天安门(tam) 大理(dl) 泉州(qz) 少林(shl)华山(hs) 灵鹫(lj)  
武当(wd)    明教(mj) 扬州(gc) 星宿(xx) 雪山(xs) 峨眉(em)  
全真(quz)  白驼山(bt) 古墓(gm) 苏州(sz)归云庄(gyz)襄阳(xy)  \n"NOR, me);

}
     if (me->move(pla)) {
          message_vision(HIG
"$N对"+query("name")+HIG"说：这附近有没有马车，我们要赶路了\n"+
query("name")+HIG"在附近叫了一匹马车，\n$N和"+query("name")+HIG"双双上马，向外飞跑而去。。。\n\n"NOR, me);
       message_vision(HIC"\n一路奔驰，终于到了！你和"+query("name")+HIC"双双飞身一跃，跳下马车。\n"NOR,me);
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
return notify_fail("你要看谁的状态？\n");
if (arg !=query("id"))
return notify_fail("你要看谁的状态？\n");
	my = query_entire_dbase();
	 printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);
printf(HIC"精力："NOR"%s%3d/ %3d %s(%3d%%)   "HIC"气血："NOR"%s%3d/ %3d %s(%3d%%)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]            
	);		
	printf(HIW"主人： "HIG"%s"NOR"\t\t"HIW"经验： "HIG"%d"NOR"\t\t"HIW"杀气： "HIG"%d"NOR"\n"NOR,
	my["host_id"], my["combat_exp"],my["bellicosity"]
	);
        printf(HIY"悟性： "HIG"%d"NOR"\t\t"HIY"根骨： "HIG"%d"NOR"\t\t"HIY"容貌： "HIG"%d"NOR"\n"NOR,
        query_int(), query_con(),query_per()
        );
        printf(HIY"身法： "HIG"%d"NOR"\t\t"HIY"臂力： "HIG"%d"NOR"\t\t"HIY"福缘： "HIG"%d"NOR"\n"NOR,
        query_dex(), query_str(),query_kar()
        );
        printf(HIY"内力： "HIG"%d"NOR"\t\t"HIY"内力上限： "HIG"%d"NOR"\t\t\n"NOR,
        query("neili"), query("max_neili")
        );

        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf(HIR"攻击力： %d\t"NOR+HIR"防御力： %d\t\n"NOR,
        at_pt+1, pa_pt/2+do_pt/2+1
        );
	printf("/cmds/skill/skills"->pet_skill(this_object()));
	 printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);return 1;
}


// 永久跟随主人 (by xbd)
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
		command("say 主人等等我！！！");
		move(environment(me));
		command("say 主人，别走那么快，我差点跟不上了！");
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
			command("say 不好，主人有危险！！！");
			move(environment(me));
		}
		command("say 主人有难，我一定会誓死保护你的！！！");
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
	command("say  主人不在，我回家算了。");
	command("emote 往人群里一闪就不见了。");
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
		return notify_fail("嗯....你得先把" + this_object()->name() + "弄醒再说。\n");

if (me->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");
if (this_object()->is_busy())
return notify_fail("他正忙着呢！\n");

        if (environment(me)->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( (int)me->query("qi") < 50 )
		return notify_fail("你没有那么多的气！\n");

	if( (int)me->query("jing") < 50 )
		return notify_fail("你现在精不够！\n");
if( environment(me)->query("outdoors") ) 
          return notify_fail(HIY"\n不要影响别人，还是找一个室内的地方吧。\n"NOR);

        if (environment(me)->query("sleep_room"))
                return notify_fail("卧室不能讨论，会影响别人休息。\n");

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");

	if (me->query("potential") - me->query("learned_points") < 0) 
         return notify_fail("你的潜能太少了！\n");	

	if (!arg) return notify_fail("你要与"+query("name")+"讨论什么？\n");
	if (!me->query_skill(arg,1))
		return notify_fail("你不会这种技能。\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("这个武功好像从特殊技能中领悟。\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 20) {
		me->receive_damage("jing",bl/2);
		return notify_fail("你没办法集中精神。\n");
	}
	if(me->query("potential") < 100 ) 
         return notify_fail("你的潜能太少了！\n");	

	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("你的"+to_chinese(special)+"造诣不够，无法对更深一层的"+CHINESE_D->chinese(arg)+"进行讨论。\n");
	write(HIY"你和"+query("name")+HIY"席地而坐，开始对"+to_chinese(arg)+HIY"的使用方法和体会进行和讨论。\n"NOR);
	me->receive_damage("jing",bl/2);
	me->improve_skill(arg,sl/5+2);
	write(HIG"在"+query("name")+HIG"的帮助和你的努力下。\n你对"+to_chinese(arg)+HIG"好像有了更深一层的了解！\n"NOR);
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
return notify_fail("你没有武器！\n");
if (!weapon1) 
return notify_fail("他没有武器！\n");

if (me->query("id")!=query("host_id"))
return notify_fail("你无权使用这个命令！\n");
if (this_object()->is_busy())
return notify_fail("他正忙着呢！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if (this_object()->is_busy())
                return notify_fail("他现在正忙着呢。\n");

        if (environment(me)->query("no_fight"))
                return notify_fail("这里不能战斗。\n");

        if (! arg)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        } else
                target = present(arg, environment(me));

        if (! target || ! me->is_fighting(target))
                return notify_fail("合击只能对两人都在战斗中的对手使用。\n");

        if (! target || ! this_object()->is_fighting(target))
                return notify_fail("合击只能对两人都在战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧!\n");

        message_combatd(HIY " $N" HIY "和$n" HIY "两人眼神一交，心意已"
                        "然相通，不由的会心一笑，只见二人身形一错，霎时\n"
                        " 已经向" + target->name() + "攻出数招！\n" NOR,
                        me, this_object());
if (random(this_object()->query("combat_exp")) >target->query("combat_exp")/3)
{
                        msg = HIG " "+query("name")+ HIG "弹" + weapon1->name() +
                              HIG"轻吟，宛若黄莺出谷，飘身而进，手中的" +
                              weapon1->name() + HIG "化作流星夜雨，披向"+target->query("name")+" "
                              HIG "。\n" NOR;
target->start_busy(4);
msg += HIR " 结果"+target->query("name")+HIR"被"+query("name")+HIR"闹个手忙脚乱，惊慌失措，呆在当场，不知如何应对！\n" NOR;
message_combatd(msg, me, target);
          message_combatd(HIW" " + me->name() + HIW"见" + query("name") + HIW"得手，急向前跃，补足了" + query("name") + HIW"的破绽，并连连出招！\n" NOR,
                        me, this_object());
                        msg = HIC " " + me->name() + HIC"纵声长啸，一股杀气凛然而起，天"
                              "地登时色变，$N" HIC "挟风雷万钧之势，压向"+target->query("name")+HIC"
                              。\n" NOR;
extra=(int)me->query_skill("force",1)/10;
extra1=(int)this_object()->query_skill("force",1)/10;	
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	this_object()->add_temp("apply/attack", extra1);
	this_object()->add_temp("apply/damage", extra1);

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC " " + query("name") + HIC"紧跟着，从左面又是一击！\n" NOR;
	COMBAT_D->do_attack(this_object(),target, weapon1, TYPE_REGULAR,msg);
msg = HIW " " + me->query("name") + HIW"紧跟着，从右面又是一击！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC " " + query("name") + HIC"最后，从上面补足一击！\n" NOR;
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
          message_combatd(" " + target->name() + "急向后跃，跳出了被合击的范围！\n" NOR,
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
		return notify_fail("你无权使用这个命令！\n");

	if( !arg ) 
		return notify_fail("你想让他练习什么武功？\n");

	if ((sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("指令格式：lianxi <技能种类> <次数>\n");

	if( !living(ob) )
		return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (where->query("sleep_room"))
                return notify_fail("卧室不能互练，会影响别人休息。\n");
	if( environment(me)->query("no_beg") &&	environment(me)->query("no_fight") && environment(me)->query("no_steal")) 
		return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");
	if (ob->is_busy())
		return notify_fail("他现在正忙着呢。\n");
	if( ob->is_fighting() )
		return notify_fail("他已经在战斗中了，学一点实战经验吧。\n");

	if ( times < 1 || times > 30)
		return notify_fail("互练次数必须大于一次，但不能超过三十次。\n");
	if( !stringp(skillname = ob->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	skill_basic = ob->query_skill(arg, 1);
	skill = ob->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("他好像还没有学过这项技能吧？\n");
	if( skill_basic < 1 )
		return notify_fail("他对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("他的基本功火候未到，必须先打好基础才能继续提高。\n");

	notify_fail("他现在不能练习这项技能。\n");

	if (skill*skill*skill/10 > (int)ob->query("combat_exp")) 
		return notify_fail("也许是缺乏实战经验，他的练习总没法进步。\n");

//	if( !SKILL_D(skillname)->valid_learn(ob) ) return 0;

	notify_fail("他试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");

	write( HIW "在你的指导下，" + ob->name() + "把" + to_chinese(skillname) + HIW"练习了"+chinese_number(times)+"趟。\n" NOR);
	if (skill*skill*skill/10 > (int)ob->query("combat_exp")) 
	{
                me->start_busy(1);
		return notify_fail("也许是缺乏实战经验，他的练习总没法进步。\n");
		return 1;
	}

	for (pertimes = 1; pertimes <= times; pertimes ++)
	{
// 用自己的jing、qi、neili来进行练习
		jing = random(200);
		qi = random(400);
		neili = random(200);
		if (me->query("jing") < jing)
			return notify_fail("你的精气太低了，无法继续指导他的练习！\n");
		if (me->query("qi") < qi)
			return notify_fail("你的气血太低了，无法继续指导他的练习！\n");
		if (me->query("neili") < neili)
			return notify_fail("你的内力太低了，无法继续指导他的练习！\n");
		me->add("jing", -jing);
		me->add("qi", -qi);
		me->add("neili", -neili);
		ob->improve_skill(skillname, (skill_basic/5 +1), skill_basic > skill? 0: 1);
	}
	write( HIY + ob->name() + "的" + to_chinese(skillname) + "进步了！\n" NOR);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!query("no_accept") || who == query("possessed")) {
		command("thank " + who->query("id"));
		return 1;
	}
	command("shake " + who->query("id"));
	command("say 主人和我说过，别随便拿别人的东西！");
	return 0;
}

int accept_fight(object ob)
{
	if (!query("no_fight") || ob == query("possessed")) {
		command("say 好吧，你小心了！");
		return 1;
	}
	command("shake " + ob->query("id"));
	command("say 主人和我说过，不要随便和别人动武！");
	return 0;

}

int do_order(string arg)
{
	object me = this_player();
	string type, cmd;
	int i;
	
	seteuid(getuid());

	if (me->query("id") != query("host_id"))
		return notify_fail("你无权使用这个命令！\n");
	if( !arg ) 
		return notify_fail("你想让他做什么？\n");
	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		return notify_fail("指令格式：order [un]accept object | [un]accept fight | <指令>\n");
	if (!living(this_object()))
		return notify_fail("以他目前的状态，怎么可能听你的命令呢？\n");

	if (type == "accept") {
		if (cmd == "object") {
			me->set("guard/status/no_accept", 0);
			set("no_accept", 0);
			command("nod");
			command("say 好的，我以后就代你接受别人的东西吧！");
			return 1;
		}
		if (cmd == "fight") {
			me->set("guard/status/no_fight", 0);
			set("no_fight", 0);
			command("nod");
			command("say 好的，我以后也和别人一起切磋切磋武艺！");
			return 1;
		}
		return notify_fail("指令格式：order accept object|fight\n");
	}

	if (type == "unaccept") {
		if (cmd == "object") {
			me->set("guard/status/no_accept", 1);
			set("no_accept", 1);
			command("nod");
			command("say 好的，我以后再也不随便接受别人的东西了！");
			return 1;
		}
		if (cmd == "fight") {
			me->set("guard/status/no_fight", 1);
			set("no_fight", 1);
			command("nod");
			command("say 好的，我以后再也不随便和别人比武了！");
			return 1;
		}
		return notify_fail("指令格式：order unaccept object|fight\n");
	}

	for (i = 0; i < sizeof(cmds); i++)
		if (cmds[i] == type) {
			exec_cmd(me, arg);
			return 1;
		}

	return notify_fail("你只能对他下达战斗指令！\n");
}

void exec_cmd(object me, string arg)
{
	if (!command(arg))
		write("他现在无法正确执行你的命令！\n");
	else
		write("遵命，主人！\n");
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
		message_vision(HIR "比武之地，只分胜负，不分生死。$N被打败了但却偷得一命。\n" NOR, ob);
		ob->set("jing", 50);	
		ob->set("eff_jing", 50);
		ob->set("qi", 50);
		ob->set("eff_qi", 50);
                ob->remove_all_killer();
		all_inventory(environment())->remove_killer(ob);
                ob->revive(1);
                return;
	}
	command("say 对不起主人，我无法再服侍你了，你一定要好好保重自己！");
	//tell_object(ob->query("possessed"), HIG"对不起主人，我无法再服侍你了，你一定要好好保重自己！\n"NOR);
	// skills - 2
	ob->skill_death_penalty();
	ob->skill_death_penalty();
	::die();
}

int do_name(string arg)
{
	object me = this_player();
	
	if (me->query("id") != query("host_id"))
		return notify_fail("你无权使用这个命令！\n");
	if (!arg || arg == "") 
		return notify_fail("你想帮他改什么名字？\n");
	if (!living(this_object()))
		return notify_fail("以他目前的状态，怎么可能听你的命令呢？\n");
	if (!LOGIN_D->check_legal_name(arg))
		return 1;

	command("say 从今以后我就叫做" + arg + "了！");
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
		return notify_fail("你无权使用这个命令！\n");
	if (!arg || arg == "") 
		return notify_fail("你想把他的描述改为什么？\n");
	if (!living(this_object()))
		return notify_fail("以他目前的状态，怎么可能听你的命令呢？\n");
	
	if (arg == "none") {
		me->delete("guard/long");
		delete("long");
		command("thank " + me->query("id"));
		return 1;
	}

	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 )
		return notify_fail("请将对他的描述控制在八行以内。\n");

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
		return notify_fail("你无权使用这个命令！\n");
	if (!arg || arg == "") 
		return notify_fail("你想把他的称号改为什么？\n");
	if (!living(this_object()))
		return notify_fail("以他目前的状态，怎么可能听你的命令呢？\n");
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
		return notify_fail("你无权使用这个命令！\n");
	if (!living(this_object()))
		return notify_fail("以他目前的状态，怎么可能听你的命令呢？\n");

	if (!arg || arg == "") {
		write(HIG"他现在的战斗指令阵列为：\n"NOR);
		for (i = 1; i <= 5; i++)
			if (stringp(cmd = me->query(sprintf("guard/status/ticks/%d", i))))
				write(sprintf("%d - %s\n", i, cmd));
			else
				write(sprintf("%d - %s\n", i, "<空缺>"));
		return 1;
	}

	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		return notify_fail("指令格式：ticks [1-5 <指令>] | [-d 1-5|all]\n");

	if (type == "1" || type == "2" || type == "3" || type == "4" || type == "5") {
		if (sscanf(cmd, "%s %s", cmd1, cmd2) < 2)
			cmd1 = cmd;
		for (i = 0; i < sizeof(cmds); i++)
			if (cmds[i] == cmd1) {
				me->set("guard/status/ticks/" + type, cmd);
				command("en " + query("id"));
				return 1;
			}
		return notify_fail("你所设定的只能是战斗指令！\n");
	} else if (type == "-d" && (cmd == "1" || cmd == "2" || cmd == "3" || cmd == "4" || cmd == "5"))
		me->delete("guard/status/ticks/" + cmd);
	else if (type == "-d" && cmd == "all")
		for (i = 1; i <= 5; i++)
			me->delete(sprintf("guard/status/ticks/%d", i));
	else
		return notify_fail("指令格式：ticks [1-5 <指令>] | [-d 1-5|all]\n");

	command("en " + query("id"));
	
	return 1;
}

int check_legal_title(string name)
{
	int i = strlen(name);
	
	if( (strlen(name) < 8) || (strlen(name) > 20 ) ) {
		write("对不起，称号必须是 4 到 10 个中文字。\n");
		return 0;
	}

	while(i--) {
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("对不起，称号不能用控制字元。\n");
			return 0;
		}
		if( (strsrch(name, "　") >= 0) ||
		    (strsrch(name, "爸") >= 0)) {
			write("对不起，称号不能用引起误会的单字。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("对不起，称号必须使用中文字。\n");
			return 0;
		}
	}
	return 1;
}
