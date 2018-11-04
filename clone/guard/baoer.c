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
              obj->set("long", RED+"һ��������" + nmstr + "��\n" + NOR);
        obj->set("liquid/name", nmstr);
write( HIG "��:"+nmstr+HIG"�����ˡ�"+"\n" NOR);
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
              obj->set("long", YEL+"һ���ɿڵ�" + nmstr + "��\n" + NOR);
        obj->set("liquid/name", nmstr);
write( HIG "ݱ:"+nmstr+HIG"����ˡ�"+"\n" NOR);
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
              obj->set("long", GRN+"һ����������, �������"+nmstr+"��\n"+NOR);
write( HIG "��:"+obj->query("name")+HIG"�����ˡ�"+"\n" NOR);
        obj->move(me);
}
void create()
{
        set_name(HIW"����"NOR, ({ "shi tong",  "shitong"}));
	set("title", HIM "�����绪" NOR);
	set("long", HIG "������ȥֻ��ʮ���꣬�������������ٷ磬�������Ρ�\n"+
	"������˫Ŀ��ȴ������һ�������������\n"+
	"�ƺ����ڸ�̾�˼��ɣ�������޳���\n" NOR);
        set("marry","hxsd");
        set("gender", "����");
 	set("age", 18);
        set("str", 50);
        set("cor", 50);
        set("baohu","hxsd");
        set("couple/couple_name","С����");
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
        set_skill("yunv-xinfa", 400);    //��Ů�ķ�
        set_skill("sword", 400);
        set_skill("yunv-jian", 400);     //��Ů��
        set_skill("quanzhen-jian",400);  //ȫ�潣
        set_skill("dodge", 400);
        set_skill("yunv-shenfa", 400);   //��Ů����
        set_skill("parry", 400);
        set_skill("hubo", 400);          //˫�ֻ���
        set_skill("unarmed",400);
        set_skill("meinv-quan", 400);    //��Ůȭ��
        set_skill("literate",400);
        set_skill("qufeng",400);         //����֮��
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
		(: command, "emote գ��գ�۵������ǲ�����·�˰ɣ�����" :),
                (:random_chat:),
             (:random_chat:),
             (:random_chat:),
             (:random_chat:),             	             	
        }) );

	set("inquiry", ([
		"��" : (: ask_go :),
		"����" :  (: ask_kiss :),
		"�ȴ�" :  (: ask_wait :),
		"�ؼ�" :  (: ask_home :),
		"����" :  (: ask_eat :),
		"��ͨ����" :  (: ask_fight :),
		"һ�㹥��" :  (: ask_fight1 :),
		"ȫ������" :  (: ask_fight2 :),
		"ǣ�ƹ���" :  (: ask_fight3 :),
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
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

        if(me->is_busy())
{
command("say ���ˣ���̫æ�ˣ��Ұﲻ���㣡");
        return notify_fail("����һ��������û����ɡ�\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
	   if(random(10)>7)	          
           {
	   say(query("name")+"�����ߵ�ͨ�죬����ͷ���������ĵ��˵�ͷ��\n");
           command("lovelook "+ me->query("id") );
           command("cat "+ me->query("id") );
           command("kiss "+ me->query("id") );
           write(CYN"���"+query("name")+CYN"΢΢һЦ����¶�����޵�ϲ��֮�顣\n"NOR);
           write(CYN" "+query("name")+CYN"�����ע�����㣬˫Ŀ�̺���ŨŨ�İ��⡣\n"NOR);
           command("makelove "+ me->query("id") );
           me->start_busy(1);
           this_object()->start_busy(1);
           }		
           else 
{
	   me->start_busy(1);
           this_object()->start_busy(1);
	   say(query("name")+"����һ����һ����������ȥ��˵�����У������ԡ�\n");
	   return 1;
}
           }
//	}
//else say(query("name")+"˵�����ޣ��Ҳ��ɡ�");
return 1;
}

int ask_go()
{
  object me;
  string new_name,new_id,host_id;
   me=this_player();
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

//	   if(query("id")!="bao er")
//        {
//		 sscanf(query("id"),"%s's bao er",host_id);
		 if(query("id")==query("host_id"))
           {say(query("name")+"�����۾����˿�"+
				me->query("name")+"��˵����ȻԸ�������Ҷ�����ġ�\n");
            return 1;
           }
	 if(me->query("id")!=query("host_id"))
           {say(query("name")+"�����۾����˿�"+
				me->query("name")+"��˵�����еģ��ҵ��������˵ġ�\n");
			return 1;
           }
//	 }
	   command("nod");
	   command("say ���˴��Ҷ�����ɽ����һ���ᾡ�ľ����ķ����㣡");
           set_leader(me);
return 1;
}

int ask_wait()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

        if(me->is_busy())
{
command("say ���ˣ���̫æ�ˣ��Ұﲻ���㣡");
        return notify_fail("����һ��������û����ɡ�\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
           command("inn " + me->query("id"));
           command("say ����ʱ��������㣬�����ʲô�£��ǵ��ٻ���Ŷ��");
           set_leader(0);
	   return 1;
           }
//	}
//say(query("name")+"˵��:����˭�����ֲ���ʶ�㣬�Ͳ�����ģ�");
return 1;
}

int ask_home()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
	if (this_object()->is_busy())
		return notify_fail("������æ���ء�\n");
	if( this_object()->is_fighting() )
		return notify_fail("�Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

        if(me->is_busy())
{
command("say ���ˣ���̫æ�ˣ��Ұﲻ���㣡");
        return notify_fail("����һ��������û����ɡ�\n");
return 1;
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
	if (is_busy() || is_fighting()) {
		command("say ����æ�ţ���һ���ٻ�ȥ��");
		return 1;
	}
	   if(random(10)>3)	          
           {
	   message("vision",
		 name() + "˵������������Ҫ�ҷ������뷢��Ϊ�����ҵ��㰡��\n\n"
		+ name() + "����������ʧ�����ˡ�\n" , environment(),
		this_object() );
	   destruct(this_object());
           }		
           else 
	   say(query("name")+"����һ��,����ϸ���˵:����"+me->query("name")+"����,��Ҫ.�Ҳ�Ҫ�ؼ�\n");
	   return 1;
           }
//	}
//say(query("name")+"˵��:����˭�����ֲ���ʶ�㣬�Ͳ�����ģ�");
return 1;
}

int ask_fight()
{
  object me;
  string new_name,new_id;
  me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

        if(me->is_busy())
{
command("say ���ˣ���̫æ�ˣ��Ұﲻ���㣡");
        return notify_fail("����һ��������û����ɡ�\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say �õģ��Ҿ���С�ģ����������ˣ�");
           change_combat_mode(me, 0);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" �Ҳ���ʶ�㰡��");
return 1;
}

int ask_fight1()
{
  object me;
  string new_name,new_id;
  me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

        if(me->is_busy())
{
command("say ���ˣ���̫æ�ˣ��Ұﲻ���㣡");
        return notify_fail("����һ��������û����ɡ�\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say �´�ս����һ��С�ĳ��У�");
           change_combat_mode(me, 1);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" �Ҳ���ʶ�㰡��");
return 1;
}

int ask_fight2()
{
  object me;
  string new_name,new_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

        if(me->is_busy())
{
command("say ���ˣ���̫æ�ˣ��Ұﲻ���㣡");
        return notify_fail("����һ��������û����ɡ�\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say �´�ս����һ�����ҵ�ȫ���������֣�");
           change_combat_mode(me, 2);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" �Ҳ���ʶ�㰡��");
return 1;
}

int ask_fight3()
{
  object me;
  string new_name,new_id;
  me=this_player();
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

        if(me->is_busy())
{
command("say ���ˣ���̫æ�ˣ��Ұﲻ���㣡");
        return notify_fail("����һ��������û����ɡ�\n");
return 1;
}

	 if(me->query("id")==query("host_id"))

           {
           command("nod "+ me->query("id"));
           command("say �´�ս����һ�����ҵ�ȫ��ǣ�ƶ��֣�");
           change_combat_mode(me, 3);
 	   return 1;
           }		
else           command("say "+ me->query("name")+" �Ҳ���ʶ�㰡��");
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
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

        if(me->is_busy())
{
command("say ���ˣ���̫æ�ˣ��Ұﲻ���㣡");
        return notify_fail("����һ��������û����ɡ�\n");
return 1;
}

        obs = filter_array(all_inventory(me), (: ! $1->query("equipped") :));
        if (sizeof(obs) >= 38            )
{
write( CYN "�����ϵĶ���ʵ����̫���ˣ�û�����óԵĶ����ˡ�"+"\n" NOR);
                return notify_fail("�����ϵĶ���ʵ����̫���ˣ�û�����óԵĶ����ˡ�\n");
}
if (inv)
{
		sizeinv=sizeof(inv);
		while (sizeinv--)
		{
       			if (inv[sizeinv]->query("guardfood"))
{
write( CYN "�����ϻ��гԵĶ���û������"+"\n" NOR);
     				return notify_fail("�����ϲ����гԵ���\n");
}    		
		}
}

//  if(query("id")!="bao er")
//        {
//	 sscanf(query("id"),"%s's bao er",host_id);
	 if(me->query("id")==query("host_id"))
           {
me = this_player();
message_vision("$N�ó���һЩ�������ϣ������˻�Ϊ����$n������������\n",this_object(),me);
       write( CYN ".................."+"\n" NOR);
       write( CYN "..............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN "........."+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "."+"\n" NOR);
       write( CYN " "+query("name")+"������ķ�װ�ڼ�������������㡣"+"\n" NOR);
       write( CYN " "+query("name")+"�ӻ����ó���������ͷ��վ�����Ա߳���������"+"\n" NOR);
me->start_busy(6);
this_object()->start_busy(6);
            set ("food",170);
            set ("water",170);
if (random(30)>25)
create_water(HIW"����"NOR, ({ "milk" }), CYN"�໨��"NOR );
else if (random(30)>20)
create_water(GRN"������"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
else if (random(30)>20)
create_water(GRN"���ݴ�"NOR, ({ "tea" }), MAG"��ɰյ"NOR );
else if (random(30)>20)
create_water(HIG"��ɽ����"NOR, ({ "tea" }), RED"����յ"NOR );
else if (random(30)>20)
create_water(HIR"��ë��"NOR, ({ "tea" }), CYN"����յ"NOR );
else if (random(30)>20)
create_water(GRN"������"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
else if (random(30)>20)
create_water(HIG"������"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
else if (random(30)>20)
create_water(RED"�ն���"NOR, ({ "tea" }), WHT"ˮ��յ"NOR );
else if (random(30)>20)
create_water(HIG"��ɽ����"NOR, ({ "tea" }), RED"����յ"NOR );
else 
create_water(HIW"����"NOR, ({ "milk" }), WHT"������"NOR );
if (random(30)>25)
                create_wine(HIW"�ھ�"NOR, ({ "wine" }), WHT"��֬����"NOR );
else if (random(30)>20)
                create_wine(WHT"����׾�"NOR, ({ "wine" }), YEL"Ϭ�Ǳ�"NOR );
else if (random(30)>20)
                create_wine(RED"���Ѿ�"NOR, ({ "wine" }), HIW"ҹ�Ɑ"NOR );
else if (random(30)>20)
                create_wine(WHT"������"NOR, ({ "wine" }), CYN"��ͭ��"NOR );
 else if (random(30)>20)
                create_wine(HIG"�ٲݾ�"NOR, ({ "wine" }), RED"���ٱ�"NOR );
else if (random(30)>20)
                 create_wine(HIR"״Ԫ��"NOR, ({ "wine" }), WHT"�Ŵɱ�"NOR );
else if (random(30)>20)
                 create_wine(GRN"�滨��"NOR, ({ "wine" }), HIG"��䱭"NOR );
else if (random(30)>20)
                 create_wine(HIW"��¶��"NOR, ({ "wine" }), WHT"������"NOR );
else if (random(30)>20)
                 create_wine(RED"���껨��"NOR, ({ "wine" }), HIW"�δɱ�"NOR  );
else if (random(30)>20)
                 create_wine(WHT"����Һ"NOR, ({ "wine" }), WHT"������"NOR );
else if (random(30)>20)
                 create_wine(WHT"�׾�"NOR, ({ "wine" }), HIW"�´ɱ�"NOR );
else if (random(30)>20)
                 create_wine(HIR"�ſ���"NOR, ({ "wine" }), HIG"��ͭ��"NOR  );
else if (random(30)>20)
                 create_wine(HIW"͸ƿ��"NOR, ({ "wine" }), WHT"������"NOR  );
else if (random(30)>20)
                 create_wine(WHT"�׾�"NOR, ({ "wine" }), HIW"�´ɱ�"NOR );
else if (random(30)>20)
                 create_wine(GRN"��Ҷ��"NOR, ({ "wine" }), GRN"��䱭"NOR );
else if (random(30)>20)
                 create_wine(YEL"���˻ƾ�"NOR, ({ "wine" }), HIY"������"NOR );
else if (random(30)>20)
                 create_wine(HIR"Ů����"NOR, ({ "wine" }), MAG"��̴��"NOR );
else if (random(30)>20)
                 create_wine(WHT"ę́��"NOR, ({ "wine" }), YEL"�̽�"NOR );
else if (random(30)>20)
                 create_wine(RED"�𻨾�"NOR, ({ "wine" }), WHT"������"NOR );
else if (random(30)>20)
                 create_food(YEL"���ֻ���"NOR,({"peanut"}) );
else 

if (random(40)>35)
                create_food(HIR"�������"NOR,({"jujube"}) );
if (random(40)>35)
                create_food(HIW"���͹���"NOR,({"melon seeds","seeds"}) );
if (random(40)>35)
                create_food(HIG"���ݴ���"NOR, ({ "spring roll","roll" }) );
if (random(40)>35)
                create_food(HIC"��Ƭ����"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIW"������˺��"NOR, ({"chicken"}) );
if (random(40)>35)
                create_food(HIR"��������"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIY"����ˮ��"NOR, ({ "dumpling" }) );
if (random(40)>35)
                create_food(RED"�������"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIR"�ͼ��з"NOR, ({ "crab" }) );
if (random(40)>35)
                create_food(HIY"������"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(YEL"�ҳ�����"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(HIY"���ݰǼ�"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(HIG"���ݴ���"NOR, ({ "spring roll","roll" }) );
if (random(40)>35)
                create_food(HIC"��Ƭ����"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(YEL"��ଷ�"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(RED"�����Ƭ"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(RED"���⴮"NOR, ({ "mutton" }) );
if (random(40)>35)
                create_food(HIR"������"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIY"������Ѽ"NOR, ({ "duck" }) );
if (random(40)>35)
                create_food(YEL"������"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(HIW"��ϲ����"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(YEL"�л���"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(HIW"��ϲ����"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(HIG"���ݴ���"NOR, ({ "spring","roll" }) );
if (random(40)>35)
                create_food(HIC"��Ƭ����"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(RED"���⴮"NOR, ({ "mutton" }) );
if (random(40)>35)
                create_food(HIY"��֦����"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(HIR"������˿"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(HIY"���ݰǼ�"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(RED"�������"NOR, ({ "chrafing dish","dish" }) );
if (random(40)>35)
                create_food(HIY"������Ѽ"NOR, ({ "duck" }) );
if (random(40)>35)
                create_food(HIW"��ն��"NOR, ({ "chicken" }) );
if (random(40)>35)
                create_food(YEL"������"NOR, ({ "meat" }) );
if (random(40)>35)
                create_food(HIR"������"NOR, ({ "chafing dish","dish" }) );
if (random(40)>35)
                create_food(HIR"���Ŷ���"NOR, ({ "bean curd" }) );
if (random(40)>35)
                create_food(RED"�����Ƭ"NOR, ({"fish meat","meat"}) );
if (random(40)>35)
                create_food(YEL"��ଷ�"NOR, ({"rice"}) );
if (random(40)>35)
                create_food(HIW"������˺��"NOR, ({"chicken"}) );
if (random(40)>35)
                create_food(HIR"��������"NOR, ({"fish"}) );
if (random(40)>35)
                create_food(HIY"����ˮ��"NOR, ({ "dumpling" }) );              return 1;
              return 1;

           }
//	}
//say(query("name")+"����ʲôΪ�����������ֲ��������ˣ���");
//command("kick "+ me->query("id") );
return 1;
}

int do_att(string arg)
{
  object ob; 
  string host_id;
  object me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

//  if(query("id")=="bao er")
//   {say("����Ȩʹ�ô����\n");
//    return 0;}
// sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
  return notify_fail(" "+query("name")+"�����������㣡\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail(" "+query("name")+"ɵɵ�������㣬�����������˼��\n");
  if(!living(ob)) 
	 return notify_fail(" "+query("name")+"˵:"
              +ob->query("name")+"�Ѿ��������㻹Ҫ...��������\n");
// ����ɱ�Լ�
	if (userp(ob) && ob == me->query("possessed"))
		return notify_fail("����ˣ�����ɱô��\n");
// ���� pk exp < �Լ������ (by xbd)
	if (userp(ob) && ob->query("combat_exp") < me->query("combat_exp"))
		return notify_fail("�㲻���۸����Լ���С����ң�\n");
        if (userp(ob)
         && ob->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(ob)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if(userp(ob) && ob->query_condition("nokill")
    && !ob->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");	
  message_vision(name()+"��$N��ͷ��: �ţ��õġ�\n",this_player());
command("hit "+ob->query("id"));
//  fight_ob(ob);
  return 1;
}

int do_ting()
{
   string host_id;
  object me=this_player();
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

//  if(query("id")=="bao er")
//   return notify_fail("����Ȩʹ�ô����\n");
//  sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
   return notify_fail(" "+query("name")+"�����������㣡\n");
 if(!is_fighting())
	 return notify_fail(" "+query("name")+"����û���˴򶷡�\n");
 message_vision(" "+query("name")+"������$N΢΢һЦ��������սȦ��\n",me);
command("halt");
return 1;
}

int do_send(string arg)
{
  object ob; string host_id,new_name,new_id;
  object me=this_player();
if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

//  if(query("id")=="bao er")
//   return notify_fail("����Ȩʹ�ô����\n");
//  sscanf(query("id"),"%s's bao er",host_id);
  if(me->query("id")!=query("host_id"))
   return notify_fail(" "+query("name")+"�����������㣡\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("��Ҫ�� "+query("name")+"�͸�˭��\n");
  if(!living(ob)) 
	 return notify_fail("��ֻ�ܰ�"+query("name")+"������!\n");
 message_vision(" "+query("name")+"������������������$N��˵:\n���˴��Һ�,��������;���˴��Ҳ���,�����������.\n",me);
 set_leader(ob);
 new_name = ob->query("name")+"��Ѿ��"+query("name")+" ";
	   set("long","����"+new_name+"��\n"
		"����һ���崿���׵���Ů,��Լʮ��,�������;\n"
	            "�����ü�������������˫�۾����崿����һ̶��ˮ��\n"+
	            "����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
		"һ��ѩ�׵�����,ü����С,ȴ���Ǹ������۸�,���������ؿ����㡣\n");
 new_id=ob->query("id")+"'s bao er�";
           set("possessed",ob);
           set("host_id",ob->query("id"));
 set("name",new_name);
 set("id",new_id);
 write( HIY " "+query("name")+HIY"��������"+ob->query("name")+"����������ӯӯһ�ݡ�\n" NOR);
write( "����ָ��:\natt sb ����ĳ��.\nsha sb ɱ��ĳ��.\nting ֹͣս��.
sendto sb.--��"+query("name")+"�͸�sb.
hulian skill ����ĳ�书.
taolun skill ����ĳ�书.
mache  splace������ȥĳ��.
heji   sb    �ϻ�ĳ��.
shape  id    ��״̬.\n");

 return 1;
}

int do_sha(string arg)
{
        int i ;
	object me,ob;
	object* obj;
	me = this_object();
if (this_object()->is_busy())
return notify_fail("����æ���أ�\n");
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

        if(this_player()->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

        if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("��Ҫ"+query("name")+"ɱ˭��\n");
	if(!environment(ob)->query("no_fight"))
	{
// ����ɱ�Լ�
	if (userp(ob) && ob == me->query("possessed"))
		return notify_fail("����ˣ�����ɱô��\n");
// ���� pk exp < �Լ������ (by xbd)
	if (userp(ob) && ob->query("combat_exp") < me->query("combat_exp"))
		return notify_fail("�㲻���۸����Լ���С����ң�\n");
        if (userp(ob)
         && ob->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(ob)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if(userp(ob) && ob->query_condition("nokill")
    && !ob->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");	
        message_vision(name()+"��$N��ͷ˵��: �ţ��õġ�\n",this_player());
	command("say �ߣ�����Ҫ��ɱ���㣡");
        command("hit " + ob->query("id"));
	}
	return 1;
}       

void kill_ob(object ob)
{
if (ob->query("id")==query("host_id"))
{
command("say �Ҷ����˾��ľ���,��������ΪʲôҪɱ�Ұ���");	
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
        command("say " + me->name() + "��������ʲô����Ҫ�������ˣ�");
        command("emote �������������ǰ��");
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
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (me->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");
if (this_object()->is_busy())
return notify_fail("����æ���أ�\n");

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ����ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( (int)me->query("qi") < 50 )
		return notify_fail("��û����ô�������\n");

	if( (int)me->query("jing") < 50 )
		return notify_fail("�����ھ�������\n");

        if (where->query("sleep_room"))
                return notify_fail("���Ҳ��ܻ�������Ӱ�������Ϣ��\n");
if( environment(me)->query("outdoors") ) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ�����ڵĵط��ɡ�\n"NOR);

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if( !arg ) 
		return notify_fail("��Ҫ����ʲô�书����\n");


	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("ָ���ʽ��practice|lian <��������> <����>\n");

	if ( times < 1 || times > 10)
		return notify_fail("���������������һ�Σ������ܳ���ʮ�Ρ�\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");


	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
	if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	notify_fail("�����ڲ�����ϰ����ܡ�\n");

	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
		return notify_fail("Ҳ����ȱ��ʵս���飬�����ϰ��û��������\n");

	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");

	write( HIW "����"+query("name")+"��" + to_chinese(skillname) + HIW"������"+chinese_number(times)+"�ˡ�\n" NOR);
	if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
	{
                me->start_busy(1);
		return notify_fail("Ҳ����ȱ��ʵս���飬�����ϰ��û��������\n");
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
	write( HIY "���" + to_chinese(skillname) + "�����ˣ�\n" NOR);
	return 1;
}

void destroying(object ob)
{   
object me=this_player();
command("say ������Ҫɱ�ң����������֡�����\n");
command("say �ҵ�����ࡣ����\n");
command("say "+me->query("name")+"�����Ժ��Ҳ��ܼ����ٷ������ˡ�����\n");
command("say ������ء�����\n");
command("say ���ء�����\n");
message_vision("$N˵�գ��������ض������������ĵ��ڵ��ϡ�����\n",this_object());
this_object()->die();
   return;      
}

int do_move(string arg)
{

          string pla;
          object me = this_player();
	if( !living(this_object()) )
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");
if (this_object()->is_busy())
return notify_fail("����æ���أ�\n");
if (this_player()->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");

if( me->query("jing") < 50 )
               return notify_fail("�����岻̫�ã��������ӳ��µģ�\n");
if( me->is_busy())
return notify_fail("����������æ���أ�\n");

if( !environment(me)->query("no_fight"))
{
  message_vision("ֻ���ڰ�ȫ�ĵط����ܽ�������\n"
                 ,me);
      	return 1;
}
if (!arg)
return notify_fail("����ȥ�����أ�\n");
if( !wizardp(me) && me->is_fighting()  ) 
 return notify_fail("���ںͱ��˴�ܣ�û�ս������ɣ�\n");
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
"���������Ǹ��ط�����\n"NOR, me);
               message_vision(HIY
"���������ȥ�ĵط������£�
�찲��(tam) ����(dl) Ȫ��(qz) ����(shl)��ɽ(hs) ����(lj)  
�䵱(wd)    ����(mj) ����(gc) ����(xx) ѩɽ(xs) ��ü(em)  
ȫ��(quz)  ����ɽ(bt) ��Ĺ(gm) ����(sz)����ׯ(gyz)����(xy)  \n"NOR, me);

}
     if (me->move(pla)) {
          message_vision(HIG
"$N��"+query("name")+HIG"˵���⸽����û������������Ҫ��·��\n"+
query("name")+HIG"�ڸ�������һƥ������\n$N��"+query("name")+HIG"˫˫������������ܶ�ȥ������\n\n"NOR, me);
       message_vision(HIC"\nһ·���ۣ����ڵ��ˣ����"+query("name")+HIC"˫˫����һԾ������������\n"NOR,me);
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
return notify_fail("��Ҫ��˭��״̬��\n");
if (arg !=query("id"))
return notify_fail("��Ҫ��˭��״̬��\n");
	my = query_entire_dbase();
	 printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);
printf(HIC"������"NOR"%s%3d/ %3d %s(%3d%%)   "HIC"��Ѫ��"NOR"%s%3d/ %3d %s(%3d%%)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]            
	);		
	printf(HIW"���ˣ� "HIG"%s"NOR"\t\t"HIW"���飺 "HIG"%d"NOR"\t\t"HIW"ɱ���� "HIG"%d"NOR"\n"NOR,
	my["host_id"], my["combat_exp"],my["bellicosity"]
	);
        printf(HIY"���ԣ� "HIG"%d"NOR"\t\t"HIY"���ǣ� "HIG"%d"NOR"\t\t"HIY"��ò�� "HIG"%d"NOR"\n"NOR,
        query_int(), query_con(),query_per()
        );
        printf(HIY"������ "HIG"%d"NOR"\t\t"HIY"������ "HIG"%d"NOR"\t\t"HIY"��Ե�� "HIG"%d"NOR"\n"NOR,
        query_dex(), query_str(),query_kar()
        );
        printf(HIY"������ "HIG"%d"NOR"\t\t"HIY"�������ޣ� "HIG"%d"NOR"\t\t\n"NOR,
        query("neili"), query("max_neili")
        );

        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf(HIR"�������� %d\t"NOR+HIR"�������� %d\t\n"NOR,
        at_pt+1, pa_pt/2+do_pt/2+1
        );
	printf("/cmds/skill/skills"->pet_skill(this_object()));
	 printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);return 1;
}


// ���ø������� (by xbd)
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
		command("say ���˵ȵ��ң�����");
		move(environment(me));
		command("say ���ˣ�������ô�죬�Ҳ��������ˣ�");
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
			command("say ���ã�������Σ�գ�����");
			move(environment(me));
		}
		command("say �������ѣ���һ��������������ģ�����");
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
	command("say  ���˲��ڣ��һؼ����ˡ�");
	command("emote ����Ⱥ��һ���Ͳ����ˡ�");
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
		return notify_fail("��....����Ȱ�" + this_object()->name() + "Ū����˵��\n");

if (me->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");
if (this_object()->is_busy())
return notify_fail("����æ���أ�\n");

        if (environment(me)->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ����ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( (int)me->query("qi") < 50 )
		return notify_fail("��û����ô�������\n");

	if( (int)me->query("jing") < 50 )
		return notify_fail("�����ھ�������\n");
if( environment(me)->query("outdoors") ) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ�����ڵĵط��ɡ�\n"NOR);

        if (environment(me)->query("sleep_room"))
                return notify_fail("���Ҳ������ۣ���Ӱ�������Ϣ��\n");

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");

	if (me->query("potential") - me->query("learned_points") < 0) 
         return notify_fail("���Ǳ��̫���ˣ�\n");	

	if (!arg) return notify_fail("��Ҫ��"+query("name")+"����ʲô��\n");
	if (!me->query_skill(arg,1))
		return notify_fail("�㲻�����ּ��ܡ�\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("����书��������⼼��������\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 20) {
		me->receive_damage("jing",bl/2);
		return notify_fail("��û�취���о���\n");
	}
	if(me->query("potential") < 100 ) 
         return notify_fail("���Ǳ��̫���ˣ�\n");	

	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("���"+to_chinese(special)+"���費�����޷��Ը���һ���"+CHINESE_D->chinese(arg)+"�������ۡ�\n");
	write(HIY"���"+query("name")+HIY"ϯ�ض�������ʼ��"+to_chinese(arg)+HIY"��ʹ�÷����������к����ۡ�\n"NOR);
	me->receive_damage("jing",bl/2);
	me->improve_skill(arg,sl/5+2);
	write(HIG"��"+query("name")+HIG"�İ��������Ŭ���¡�\n���"+to_chinese(arg)+HIG"�������˸���һ����˽⣡\n"NOR);
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
return notify_fail("��û��������\n");
if (!weapon1) 
return notify_fail("��û��������\n");

if (me->query("id")!=query("host_id"))
return notify_fail("����Ȩʹ��������\n");
if (this_object()->is_busy())
return notify_fail("����æ���أ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
        if (this_object()->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (environment(me)->query("no_fight"))
                return notify_fail("���ﲻ��ս����\n");

        if (! arg)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        } else
                target = present(arg, environment(me));

        if (! target || ! me->is_fighting(target))
                return notify_fail("�ϻ�ֻ�ܶ����˶���ս���еĶ���ʹ�á�\n");

        if (! target || ! this_object()->is_fighting(target))
                return notify_fail("�ϻ�ֻ�ܶ����˶���ս���еĶ���ʹ�á�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ�������!\n");

        message_combatd(HIY " $N" HIY "��$n" HIY "��������һ����������"
                        "Ȼ��ͨ�����ɵĻ���һЦ��ֻ����������һ������ʱ\n"
                        " �Ѿ���" + target->name() + "�������У�\n" NOR,
                        me, this_object());
if (random(this_object()->query("combat_exp")) >target->query("combat_exp")/3)
{
                        msg = HIG " "+query("name")+ HIG "��" + weapon1->name() +
                              HIG"������������ݺ���ȣ�Ʈ�����������е�" +
                              weapon1->name() + HIG "��������ҹ�꣬����"+target->query("name")+" "
                              HIG "��\n" NOR;
target->start_busy(4);
msg += HIR " ���"+target->query("name")+HIR"��"+query("name")+HIR"�ָ���æ���ң�����ʧ�룬���ڵ�������֪���Ӧ�ԣ�\n" NOR;
message_combatd(msg, me, target);
          message_combatd(HIW" " + me->name() + HIW"��" + query("name") + HIW"���֣�����ǰԾ��������" + query("name") + HIW"�����������������У�\n" NOR,
                        me, this_object());
                        msg = HIC " " + me->name() + HIC"������Х��һ��ɱ����Ȼ������"
                              "�ص�ʱɫ�䣬$N" HIC "Ю�������֮�ƣ�ѹ��"+target->query("name")+HIC"
                              ��\n" NOR;
extra=(int)me->query_skill("force",1)/10;
extra1=(int)this_object()->query_skill("force",1)/10;	
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	this_object()->add_temp("apply/attack", extra1);
	this_object()->add_temp("apply/damage", extra1);

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC " " + query("name") + HIC"�����ţ�����������һ����\n" NOR;
	COMBAT_D->do_attack(this_object(),target, weapon1, TYPE_REGULAR,msg);
msg = HIW " " + me->query("name") + HIW"�����ţ�����������һ����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC " " + query("name") + HIC"��󣬴����油��һ����\n" NOR;
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
          message_combatd(" " + target->name() + "�����Ծ�������˱��ϻ��ķ�Χ��\n" NOR,
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
		return notify_fail("����Ȩʹ��������\n");

	if( !arg ) 
		return notify_fail("����������ϰʲô�书��\n");

	if ((sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("ָ���ʽ��lianxi <��������> <����>\n");

	if( !living(ob) )
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ����ɣ�\n");
        if (where->query("sleep_room"))
                return notify_fail("���Ҳ��ܻ�������Ӱ�������Ϣ��\n");
	if( environment(me)->query("no_beg") &&	environment(me)->query("no_fight") && environment(me)->query("no_steal")) 
		return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
	if (ob->is_busy())
		return notify_fail("��������æ���ء�\n");
	if( ob->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if ( times < 1 || times > 30)
		return notify_fail("���������������һ�Σ������ܳ�����ʮ�Ρ�\n");
	if( !stringp(skillname = ob->query_skill_mapped(arg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	skill_basic = ob->query_skill(arg, 1);
	skill = ob->query_skill(skillname, 1);
	if( skill < 1 )
		return notify_fail("������û��ѧ������ܰɣ�\n");
	if( skill_basic < 1 )
		return notify_fail("�����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("���Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	notify_fail("�����ڲ�����ϰ����ܡ�\n");

	if (skill*skill*skill/10 > (int)ob->query("combat_exp")) 
		return notify_fail("Ҳ����ȱ��ʵս���飬������ϰ��û��������\n");

//	if( !SKILL_D(skillname)->valid_learn(ob) ) return 0;

	notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");

	write( HIW "�����ָ���£�" + ob->name() + "��" + to_chinese(skillname) + HIW"��ϰ��"+chinese_number(times)+"�ˡ�\n" NOR);
	if (skill*skill*skill/10 > (int)ob->query("combat_exp")) 
	{
                me->start_busy(1);
		return notify_fail("Ҳ����ȱ��ʵս���飬������ϰ��û��������\n");
		return 1;
	}

	for (pertimes = 1; pertimes <= times; pertimes ++)
	{
// ���Լ���jing��qi��neili��������ϰ
		jing = random(200);
		qi = random(400);
		neili = random(200);
		if (me->query("jing") < jing)
			return notify_fail("��ľ���̫���ˣ��޷�����ָ��������ϰ��\n");
		if (me->query("qi") < qi)
			return notify_fail("�����Ѫ̫���ˣ��޷�����ָ��������ϰ��\n");
		if (me->query("neili") < neili)
			return notify_fail("�������̫���ˣ��޷�����ָ��������ϰ��\n");
		me->add("jing", -jing);
		me->add("qi", -qi);
		me->add("neili", -neili);
		ob->improve_skill(skillname, (skill_basic/5 +1), skill_basic > skill? 0: 1);
	}
	write( HIY + ob->name() + "��" + to_chinese(skillname) + "�����ˣ�\n" NOR);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!query("no_accept") || who == query("possessed")) {
		command("thank " + who->query("id"));
		return 1;
	}
	command("shake " + who->query("id"));
	command("say ���˺���˵����������ñ��˵Ķ�����");
	return 0;
}

int accept_fight(object ob)
{
	if (!query("no_fight") || ob == query("possessed")) {
		command("say �ðɣ���С���ˣ�");
		return 1;
	}
	command("shake " + ob->query("id"));
	command("say ���˺���˵������Ҫ���ͱ��˶��䣡");
	return 0;

}

int do_order(string arg)
{
	object me = this_player();
	string type, cmd;
	int i;
	
	seteuid(getuid());

	if (me->query("id") != query("host_id"))
		return notify_fail("����Ȩʹ��������\n");
	if( !arg ) 
		return notify_fail("����������ʲô��\n");
	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		return notify_fail("ָ���ʽ��order [un]accept object | [un]accept fight | <ָ��>\n");
	if (!living(this_object()))
		return notify_fail("����Ŀǰ��״̬����ô��������������أ�\n");

	if (type == "accept") {
		if (cmd == "object") {
			me->set("guard/status/no_accept", 0);
			set("no_accept", 0);
			command("nod");
			command("say �õģ����Ժ�ʹ�����ܱ��˵Ķ����ɣ�");
			return 1;
		}
		if (cmd == "fight") {
			me->set("guard/status/no_fight", 0);
			set("no_fight", 0);
			command("nod");
			command("say �õģ����Ժ�Ҳ�ͱ���һ���д��д����գ�");
			return 1;
		}
		return notify_fail("ָ���ʽ��order accept object|fight\n");
	}

	if (type == "unaccept") {
		if (cmd == "object") {
			me->set("guard/status/no_accept", 1);
			set("no_accept", 1);
			command("nod");
			command("say �õģ����Ժ���Ҳ�������ܱ��˵Ķ����ˣ�");
			return 1;
		}
		if (cmd == "fight") {
			me->set("guard/status/no_fight", 1);
			set("no_fight", 1);
			command("nod");
			command("say �õģ����Ժ���Ҳ�����ͱ��˱����ˣ�");
			return 1;
		}
		return notify_fail("ָ���ʽ��order unaccept object|fight\n");
	}

	for (i = 0; i < sizeof(cmds); i++)
		if (cmds[i] == type) {
			exec_cmd(me, arg);
			return 1;
		}

	return notify_fail("��ֻ�ܶ����´�ս��ָ�\n");
}

void exec_cmd(object me, string arg)
{
	if (!command(arg))
		write("�������޷���ȷִ��������\n");
	else
		write("���������ˣ�\n");
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
		message_vision(HIR "����֮�أ�ֻ��ʤ��������������$N������˵�ȴ͵��һ����\n" NOR, ob);
		ob->set("jing", 50);	
		ob->set("eff_jing", 50);
		ob->set("qi", 50);
		ob->set("eff_qi", 50);
                ob->remove_all_killer();
		all_inventory(environment())->remove_killer(ob);
                ob->revive(1);
                return;
	}
	command("say �Բ������ˣ����޷��ٷ������ˣ���һ��Ҫ�úñ����Լ���");
	//tell_object(ob->query("possessed"), HIG"�Բ������ˣ����޷��ٷ������ˣ���һ��Ҫ�úñ����Լ���\n"NOR);
	// skills - 2
	ob->skill_death_penalty();
	ob->skill_death_penalty();
	::die();
}

int do_name(string arg)
{
	object me = this_player();
	
	if (me->query("id") != query("host_id"))
		return notify_fail("����Ȩʹ��������\n");
	if (!arg || arg == "") 
		return notify_fail("���������ʲô���֣�\n");
	if (!living(this_object()))
		return notify_fail("����Ŀǰ��״̬����ô��������������أ�\n");
	if (!LOGIN_D->check_legal_name(arg))
		return 1;

	command("say �ӽ��Ժ��Ҿͽ���" + arg + "�ˣ�");
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
		return notify_fail("����Ȩʹ��������\n");
	if (!arg || arg == "") 
		return notify_fail("���������������Ϊʲô��\n");
	if (!living(this_object()))
		return notify_fail("����Ŀǰ��״̬����ô��������������أ�\n");
	
	if (arg == "none") {
		me->delete("guard/long");
		delete("long");
		command("thank " + me->query("id"));
		return 1;
	}

	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 )
		return notify_fail("�뽫���������������ڰ������ڡ�\n");

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
		return notify_fail("����Ȩʹ��������\n");
	if (!arg || arg == "") 
		return notify_fail("��������ĳƺŸ�Ϊʲô��\n");
	if (!living(this_object()))
		return notify_fail("����Ŀǰ��״̬����ô��������������أ�\n");
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
		return notify_fail("����Ȩʹ��������\n");
	if (!living(this_object()))
		return notify_fail("����Ŀǰ��״̬����ô��������������أ�\n");

	if (!arg || arg == "") {
		write(HIG"�����ڵ�ս��ָ������Ϊ��\n"NOR);
		for (i = 1; i <= 5; i++)
			if (stringp(cmd = me->query(sprintf("guard/status/ticks/%d", i))))
				write(sprintf("%d - %s\n", i, cmd));
			else
				write(sprintf("%d - %s\n", i, "<��ȱ>"));
		return 1;
	}

	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		return notify_fail("ָ���ʽ��ticks [1-5 <ָ��>] | [-d 1-5|all]\n");

	if (type == "1" || type == "2" || type == "3" || type == "4" || type == "5") {
		if (sscanf(cmd, "%s %s", cmd1, cmd2) < 2)
			cmd1 = cmd;
		for (i = 0; i < sizeof(cmds); i++)
			if (cmds[i] == cmd1) {
				me->set("guard/status/ticks/" + type, cmd);
				command("en " + query("id"));
				return 1;
			}
		return notify_fail("�����趨��ֻ����ս��ָ�\n");
	} else if (type == "-d" && (cmd == "1" || cmd == "2" || cmd == "3" || cmd == "4" || cmd == "5"))
		me->delete("guard/status/ticks/" + cmd);
	else if (type == "-d" && cmd == "all")
		for (i = 1; i <= 5; i++)
			me->delete(sprintf("guard/status/ticks/%d", i));
	else
		return notify_fail("ָ���ʽ��ticks [1-5 <ָ��>] | [-d 1-5|all]\n");

	command("en " + query("id"));
	
	return 1;
}

int check_legal_title(string name)
{
	int i = strlen(name);
	
	if( (strlen(name) < 8) || (strlen(name) > 20 ) ) {
		write("�Բ��𣬳ƺű����� 4 �� 10 �������֡�\n");
		return 0;
	}

	while(i--) {
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ��𣬳ƺŲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( (strsrch(name, "��") >= 0) ||
		    (strsrch(name, "��") >= 0)) {
			write("�Բ��𣬳ƺŲ������������ĵ��֡�\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ��𣬳ƺű���ʹ�������֡�\n");
			return 0;
		}
	}
	return 1;
}