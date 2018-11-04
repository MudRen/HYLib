//Heart of fy3 -- Tie

//#pragma optimize all

mapping *quests;

mapping *read_table(string file);

string *roomlines;

varargs void init_dynamic_quest(int hard);

varargs int spread_quest(mapping one_quest, int hard);

object find_env(object ob);
object find_book(object ob);

varargs int already_spreaded(string str, int hard);

int quest_reward( object me, object who,object quest_item);

string dyn_quest_list();

#define MAX_DIS 7

#define MAX_ALT  2

#define MAX_DIR  8

#include <ansi.h>

string locate_obj(string str);
int random_move()
{
        mapping exits;
        string *dirs;
        object me = this_object();

//        if (!query_heart_beat(me)) return 0;
	if( !environment(me) ) return 0;
        if( me->query_temp("is_unconcious") ) return 0;

	if( !living(me)) return 0;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
        if( !environment() 
        || !mapp(exits = environment()->query("exits")) 
        || me->is_busy())
// || me->is_fighting()
        return 0;                 
//        if( !mapp(exits = environment()->query("exits")) 
//        || me->is_busy()) return 0;
        dirs = keys(exits);
        if (!dirs)  return 0;
        if (sizeof(dirs) < 1) return 0;
        command("go " + dirs[random(sizeof(dirs))]);
}

void create()

{

	string file;

	quests = read_table("/quest/dynamic_quest");

	file = read_file("/quest/dynamic_location");

	roomlines = explode(file,"\n");	

	//CRON_D->set_last_hard_dis();

	init_dynamic_quest(1);

}

int quest_reward(object me, object who,object quest_item)

{

	mapping quest;

	int exp,pot,score;

	int color;

  object ob;
	quest = quest_item->query("dynamic_quest");

	if(base_name(who) != quest["owner_name"]) return 0;

        exp =888+random(888);

        pot = exp*2/3;

        score = random(50)+50;

        me->add("combat_exp",exp);

        me->add("potential",pot);

        me->add("score",score);

	color=random(5);

	if (color>3)

	{tell_object(me,HIR"�㱻�����ˣ�\n" +

        chinese_number(exp) + "��ʵս����\n"+

        chinese_number(pot) + "��Ǳ��\n" +

        chinese_number(score)+"�㽭������\n"NOR);}

	else if (color>2)

	{tell_object(me,HIB"�㱻�����ˣ�\n" +

        chinese_number(exp) + "��ʵս����\n"+

        chinese_number(pot) + "��Ǳ��\n" +

        chinese_number(score)+"�㽭������\n"NOR);}

	else if (color>1)

	{tell_object(me,HIM"�㱻�����ˣ�\n" +

        chinese_number(exp) + "��ʵս����\n"+

        chinese_number(pot) + "��Ǳ��\n" +

        chinese_number(score)+"�㽭������\n"NOR);}

	else if (color>0)

	{tell_object(me,HIY"�㱻�����ˣ�\n" +

        chinese_number(exp) + "��ʵս����\n"+

        chinese_number(pot) + "��Ǳ��\n" +

        chinese_number(score)+"�㽭������\n"NOR);}

	else 

	{tell_object(me,HIC"�㱻�����ˣ�\n" +

        chinese_number(exp) + "��ʵս����\n"+

        chinese_number(pot) + "��Ǳ��\n" +

        chinese_number(score)+"�㽭������\n"NOR);}

	me->add("TASK",1);
    if (me->query("4zhuan")
    || me->query("5zhuan"))
{
if (random(5)==1)
{

me->add("expmax",1);

tell_object(me,HIR"��ĳɳ�������óɹ�!\n"+NOR);
}
}

if (random(12)==1)
{
        ob=new("/quest/shenshu/sdan2");
        ob->move(me);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"�õ�һ��"+HIY":" + ob->query("name")+HIG"����\n"NOR,users() );
}

	if( !undefinedp(quest["fin_func"]))

	call_other(this_object(),quest["fin_func"],me,who,quest_item);

	if(quest_item)

	destruct(quest_item);
//	destruct(present("xdshi",me));
//	tell_object(me,HIW"�����ϵ�"+HIR+"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"HIW"��������һ����ʧ�ˡ�\n"NOR);

	return 1;

}



varargs void init_dynamic_quest(int hard)

{

	int i;

	for( i=0; i < sizeof(quests); i++)

		spread_quest(quests[i],hard);

}

varargs int spread_quest(mapping quest, int hard)

{

	object obj0,obj1,obj2,obj3,jobnpc;

	object cur_obj;

	object next_obj;

	object tar;

	object *inv;

	object *target=({});

	int i;

	string location;

	if(already_spreaded(quest["file_name"],hard)) return 0;

	reset_eval_cost();

	location = roomlines[random(sizeof(roomlines))];

	obj0=find_object(location);

	if(obj0)

	obj0->reset();

	else

	obj0=load_object(location);

	cur_obj =obj0;

	if(cur_obj)

	{

	inv = all_inventory(cur_obj);

	for(i=0; i<sizeof(inv); i++) {

	if(inv[i]->is_character() && !userp(inv[i]))

	target += ({ inv[i] });

	if(inv[i]->is_container()) target += ({ inv[i] });

		}

	}

	if(!sizeof(target)) 
{
		jobnpc = new("/quest/shenshu/npc/man");
		jobnpc->move(cur_obj);
		jobnpc = new("/quest/shenshu/npc/man");
		jobnpc->move(cur_obj);
		jobnpc = new("/quest/shenshu/npc/man");
		jobnpc->move(cur_obj);
		jobnpc = new("/quest/shenshu/npc/man");
		jobnpc->move(cur_obj);
if (random(3)==0)
{
		jobnpc = new("/quest/shenshu/npc/man2");
		jobnpc->move(cur_obj);
}
}
	if(cur_obj)

	{

	inv = all_inventory(cur_obj);

	for(i=0; i<sizeof(inv); i++) {

	if(inv[i]->is_character() && !userp(inv[i]))

	target += ({ inv[i] });

	if(inv[i]->is_container()) target += ({ inv[i] });

		}

	}

	if(sizeof(target)) cur_obj = target[random(sizeof(target))];

	if(cur_obj)

	{

	tar = new(quest["file_name"]);

	tar->set("value",0);

	tar->set("dynamic_quest",quest);

	tar->move(cur_obj);		
cur_obj->set_temp("apply/attack", 30);
cur_obj->set_temp("apply/defense",130);
cur_obj->set_temp("apply/armor", 100);
cur_obj->set_temp("apply/damage", 160+random(80));
cur_obj->set("dex",150);
cur_obj->set("no_get",1);
cur_obj->set("qi",8000);
cur_obj->set("jing",8000);
cur_obj->set("eff_qi",8000);
cur_obj->set("eff_jing",10000);
cur_obj->set("max_qi",8000);
cur_obj->set("max_jing",15000);
cur_obj->set_skill("dodge",300);
cur_obj->set("chat_chance_combat", 90);
cur_obj->set("chat_msg_combat", ({ (: random_move :), }) );
cur_obj->set("chat_chance", 50);
cur_obj->set("chat_msg", ({(: random_move :),}) );
	}

return 1;

}

string dyn_quest_list()

{

	string output="";

	object owner,item;

        int i;

        for( i=0; i < sizeof(quests); i++)

	{

	reset_eval_cost();

	if(!objectp(owner= find_object(quests[i]["owner_name"])))

	owner = load_object(quests[i]["owner_name"]);

        if(!objectp(item= find_object(quests[i]["file_name"])))

        item = load_object(quests[i]["file_name"]);

	if(already_spreaded(quests[i]["file_name"]))

	{

	if(random(2))

	output += sprintf(HIG"%10s"NOR"��"HIW"%10s"NOR"��%s��\n",owner->query("name"),item->query("name"),item->query("id"));

	else

	output = sprintf(HIG"%10s"NOR"��"HIW"%10s"NOR"��%s��\n",owner->query("name"),item->query("name"),item->query("id")) + output;

	}

	else

	{

	if(random(2))

	output += sprintf(HIG"%10s"NOR"��"HIY"%10s"NOR"��%s�� [1;31m�� [32m�����[31m ��[m\n",owner->query("name"),item->query("name"),item->query("id"));

	else

	output = sprintf(HIG"%10s"NOR"��"HIY"%10s"NOR"��%s��[1;31m �� [32m �����[31m ��[m\n",owner->query("name"),item->query("name"),item->query("id")) + output;

	}

	}

//            if(random(2))output += sprintf(HIG"%10s"NOR"��"HIW"%10s"NOR"��%s��\n",item->query("owner_name"),item->query("name"),item->query("id"));
//            else output=sprintf(HIG"%10s"NOR"��"HIW"%10s"NOR"��%s��\n",item->query("owner_name"),item->query("name"),item->query("id"))+output;
//        else
//            if(random(2))output += sprintf(HIG"%10s"NOR"��"HIY"%10s"NOR"��%s�� [1;31m�� [32m�����[31m ��[m\n",item->query("owner_name"),item->query("name"),item->query("id"));
//            else output=sprintf(HIG"%10s"NOR"��"HIY"%10s"NOR"��%s��[1;31m �� [32m �����[31m ��[m\n",item->query("owner_name"),item->query("name"),item->query("id"))+output;

	return output;

}

string locate_obj(string strr)

{

        string *distance = ({

"����", "�ܽ�", "�ȽϽ�", "��Զ",

"����", "�Ƚ�Զ", "��Զ", "��Զ"

        });

        string *altitude =({

"�ߴ�", "�ط�", "�ʹ�"

        });

        string *directions=({

"��Χ","����", "�Ϸ�", "����","����",

"������","������","���Ϸ�","���Ϸ�"

        });

        object ob, tmpobj,where, *ob_list,me,obtwo,obthree,tob;

        object item,room;

        string output,outputt,dis,alt,dir,local,tlocal,ck;
        
        int i;

        int x,y,z,x0,y0,z0;

        int realdis;
	 mixed map,mapt;

        int tmp;
        string *dir1;
        string *dir2;

	string str="";

	reset_eval_cost();

        for( i=0; i < sizeof(quests); i++)

	{

        if(!objectp(item= find_object(quests[i]["file_name"])))

        item = load_object(quests[i]["file_name"]);

	if(item->query("id") == strr || item->query("name") == strr) str = quests[i]["file_name"];

	}

	if(str != "") {

                //room = environment(me);

                ob_list = children(str);

                for(i=0; i<sizeof(ob_list); i++) {
                
                ob=find_book(ob_list[i]);

                this_player()->add("jing",-5);

if(ob)
 {
ck=HIC"��"NOR;
local=ob->query("short");
tlocal=ob->query("short");                

if (wizardp(this_player()) && ob)
{
outputt ="1:"+ob->query("short")+"��\n";
}
                if(sizeof(ob->query("exits"))) 
                {
ck=chinese_number(sizeof(ob->query("exits")));
                map=values(ob->query("exits"));
if (map && sizeof(ob->query("exits"))>=1)
{
                 obtwo=load_object(map[random(sizeof(map))]);
if (ob==obtwo) obtwo=load_object(map[random(sizeof(map))]);	
if (ob==obtwo) obtwo=load_object(map[random(sizeof(map))]);		
if (ob==obtwo) obtwo=load_object(map[random(sizeof(map))]);		

if (obtwo)
{
if (wizardp(this_player())  && obtwo)
{
outputt +="2:"+obtwo->query("short")+"��\n";
}
 
                 local=obtwo->query("short");
              if(obtwo->query("exits")) 
               { //obtwoexits
                 mapt=values(obtwo->query("exits"));
if (mapt && sizeof(obtwo->query("exits"))>=1 )
{
//if (find_object(mapt[random(sizeof(mapt))]))
//{
obthree=load_object(mapt[random(sizeof(mapt))]);
if (obthree==obtwo) obthree=load_object(mapt[random(sizeof(mapt))]);
if (obthree==obtwo) obthree=load_object(mapt[random(sizeof(mapt))]);
if (obthree==obtwo) obthree=load_object(mapt[random(sizeof(mapt))]);
tob=obthree;
if (wizardp(this_player()) && obthree)
{
outputt +="3:"+obthree->query("short")+"��\n";
}

if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
tob=obthree;
if (wizardp(this_player()) && obthree)
{
outputt +="4:"+obthree->query("short")+"��\n";
}
}
}

if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
//if (tob!=obthree)
//{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);		
tob=obthree;
if (wizardp(this_player()) && obthree)
{
outputt +="5:"+obthree->query("short")+"��\n";
}
}
//}
}

if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
//if (tob!=obthree)
//{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
tob=obthree;
if (wizardp(this_player()) && obthree)
{
outputt +="6:"+obthree->query("short")+"��\n";
}
}
}
//}
/*
if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
//if (tob!=obthree)
//{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
tob=obthree;
if (wizardp(this_player()) && obthree)
{
outputt +="7:"+obthree->query("short")+"��\n";
}
}
//}
}

if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
//if (tob!=obthree)
//{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
tob=obthree;
if (wizardp(this_player()) && obthree)
{
outputt +="8:"+obthree->query("short")+"��\n";
}
}
}
*/
//}
//}
if (obthree)
{
if (obthree!= ob)
{
                 local=obthree->query("short");
} //obthree
} //obthree
} //mapt
} //map
}//obtwoexits
}
//add by hxsd
}
else local=ob->query("short");

//dir1=explode(base_name(environment(me)),"/");
dir2=explode(base_name(ob),"/");
//    if(sizeof(dir1)==3 && sizeof(dir2)==3 && dir1[0]=="d" && dir2[0]=="d" && dir1[1]!=dir2[1])
//{
      	if (dir2[1]=="baituo")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIR"����ɽ��"NOR+local+"������\n";

else if (dir2[1]=="binghuodao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIB"���𵺵�"NOR+local+"������\n";

else if (dir2[1]=="city")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"���ݵ�"NOR+local+"������\n";

else if (dir2[1]=="city2" || dir2[1]=="beijing"  || dir2[1]=="huanggon"  || dir2[1]=="huanggong" || dir2[1]=="beihai")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"�����ǵ�"NOR+local+"������\n";

else if (dir2[1]=="city4" || dir2[1]=="changan")   

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIM"�����ǵ�"NOR+local+"������\n";

else if (dir2[1]=="dali")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+RED"�����"NOR+local+"������\n";

else if (dir2[1]=="emei")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+GRN"��üɽ��"NOR+local+"������\n";

else if (dir2[1]=="foshan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+YEL"��ɽ��"NOR+local+"������\n";

else if (dir2[1]=="gaibang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+BLU"ؤ���"NOR+local+"������\n";

else if (dir2[1]=="gaochang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"�߲��Թ���"NOR+local+"������\n";

else if (dir2[1]=="guanwai")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+CYN"�����"NOR+local+"������\n";

else if (dir2[1]=="guiyun")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+MAG"����ׯ��"NOR+local+"������\n";

else if (dir2[1]=="gumu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+WHT"��Ĺ�ɵ�"NOR+local+"������\n";

else if (dir2[1]=="hangzhou")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"���ݵ�"NOR+local+"������\n";

else if (dir2[1]=="heimuya")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"��ľ�µ�"NOR+local+"������\n";

else if (dir2[1]=="hengshan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIB"��ɽ��"NOR+local+"������\n";

else if (dir2[1]=="henshan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIW"��ɽ��"NOR+local+"������\n";

else if (dir2[1]=="huanghe")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�ƺӾ�����"NOR+local+"������\n";

else if (dir2[1]=="huashan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"��ɽ��"NOR+local+"������\n";

else if (dir2[1]=="jinshe")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+YEL"����ɽ����"NOR+local+"������\n";

else if (dir2[1]=="lingjiu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"���չ���"NOR+local+"������\n";

else if (dir2[1]=="lingzhou")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIB"���ݵ�"NOR+local+"������\n";

else if (dir2[1]=="meizhuang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIM"÷ׯ��"NOR+local+"������\n";

else if (dir2[1]=="mingjiao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���̵�"NOR+local+"������\n";

else if (dir2[1]=="qingcheng")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"���ɽ��"NOR+local+"������\n";

else if (dir2[1]=="quanzhen")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIB"ȫ���ɵ�"NOR+local+"������\n";

else if (dir2[1]=="quanzhou")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"Ȫ�ݵ�"NOR+local+"������\n";

else if (dir2[1]=="shaolin")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+YEL"�����µ�"NOR+local+"������\n";

else if (dir2[1]=="shenlong")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+GRN"��������"NOR+local+"������\n";

else if (dir2[1]=="songshan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIM"��ɽ��"NOR+local+"������\n";

else if (dir2[1]=="suzhou")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"���ݵ�"NOR+local+"������\n";

else if (dir2[1]=="taishan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+MAG"̩ɽ��"NOR+local+"������\n";

else if (dir2[1]=="taohua")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+RED"�һ�����"NOR+local+"������\n";

else if (dir2[1]=="tianlongsi")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�����µ�"NOR+local+"������\n";

else if (dir2[1]=="wanjiegu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIW"��ٹȵ�"NOR+local+"������\n";

else if (dir2[1]=="wudang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+GRN"�䵱ɽ��"NOR+local+"������\n";

else if (dir2[1]=="xiakedao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+BLU"���͵���"NOR+local+"������\n";

else if (dir2[1]=="xiangyang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"�����ǵ�"NOR+local+"������\n";

else if (dir2[1]=="xiaoyao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"��ң�ֵ�"NOR+local+"������\n";

else if (dir2[1]=="xingxiu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+YEL"���޺���"NOR+local+"������\n";

else if (dir2[1]=="xueshan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIW"ѩɽ�µ�"NOR+local+"������\n";

else if (dir2[1]=="xuedao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIW"��ѩɽ��"NOR+local+"������\n";

else if (dir2[1]=="mr")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+BLU"Ľ�����ҵ�"NOR+local+"������\n";

else if (dir2[1]=="kunlun")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+WHT"����ɽ��"NOR+local+"������\n";

else if (dir2[1]=="tiezhang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIR"�����ŵ�"NOR+local+"������\n";

else if (dir2[1]=="huizhu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"���岿���"NOR+local+"������\n";

else if (dir2[1]=="yinju")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"һ�ƴ�ʦ�ӵ�"NOR+local+"������\n";

else if (dir2[1]=="menggu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"�ɹŲ�ԭ��"NOR+local+"������\n";

else if (dir2[1]=="qianjin")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIM"����ǧ��¥��"NOR+local+"������\n";

else if (dir2[1]=="lingshedao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+BLU"���ߵ���"NOR+local+"������\n";

else if (dir2[1]=="ruzhou")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+RED"���ݳǵ�"NOR+local+"������\n";

else if (dir2[1]=="kunming")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIB"������"NOR+local+"������\n";

else if (dir2[1]=="jingzhou")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"���ݵ�"NOR+local+"������\n";

else if (dir2[1]=="yanjing")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�ྩ��"NOR+local+"������\n";

else if (dir2[1]=="lanzhou" || dir2[1]=="lanzhouchen")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+YEL"���ݵ�"NOR+local+"������\n";

else if (dir2[1]=="jyguan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�����Ա������ص�"NOR+local+"������\n";

else if (dir2[1]=="changcheng")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIW"�����Ա����ǵ�"NOR+local+"������\n";

else if (dir2[1]=="fairyland")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIW"���ظ����ĺ�÷ɽׯ"NOR+local+"������\n";

else if (dir2[1]=="sdxl")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIR"��ħ�������Ĺ"NOR+local+"������\n";

else if (dir2[1]=="jqg")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"�����"NOR+local+"������\n";

else if (dir2[1]=="nio")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"ţ�Ҵ��"NOR+local+"������\n";

else if (dir2[1]=="feihu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�������ص�"NOR+local+"������\n";

else if (dir2[1]=="wuguan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"������ݵ�"NOR+local+"������\n";

else if (dir2[1]=="village")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"��ɽ���"NOR+local+"������\n";

else if (dir2[1]=="taohuacun")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIR"�һ����"NOR+local+"������\n";

else if (dir2[1]=="pingan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"ƽ���ǵ�"NOR+local+"������\n";

else if (dir2[1]=="lingxiao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIW"�����ǵ�"NOR+local+"������\n";

else if (dir2[1]=="wudujiao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIR"�嶾�̵�"NOR+local+"������\n";

else if (dir2[1]=="hj")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"��ɽ������ԭ��"NOR+local+"������\n";
else if (dir2[1]=="dali/yuxu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"��������۵�"NOR+local+"������\n";
else if (dir2[1]=="dali/wuliang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIC"��������ɽ��"NOR+local+"������\n";
else if (dir2[1]=="huanghe/yyd")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�ƺ�������"NOR+local+"������\n";
else if (dir2[1]=="kaifeng")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIM"����ǵ�"NOR+local+"������\n";
else if (dir2[1]=="feitian")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIR"������������"NOR+local+"������\n";
else if (dir2[1]=="japan")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�ձ��񻧵�"NOR+local+"������\n";
else if (dir2[1]=="tangmen")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIG"���ŵ�"NOR+local+"������\n";
else if (dir2[1]=="luoyang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�����ǵ�"NOR+local+"������\n";

else if (dir2[1]=="chengdu" || dir2[1]=="city3")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�ɶ���"NOR+local+"������\n";

else if (dir2[1]=="baihuagu")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�ٻ��ȵ�"NOR+local+"������\n";

else if (dir2[1]=="heizhao")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�ٻ��ȸ������ӵ�"NOR+local+"������\n";

else if (dir2[1]=="jiaxing")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���˵�"NOR+local+"������\n";

else if (dir2[1]=="shiliang")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�¼�ׯ��"NOR+local+"������\n";

else if (dir2[1]=="wuyi")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"����ɽ����"NOR+local+"������\n";

else if (dir2[1]=="yanping")  

	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"��ƽ�ǵ�"NOR+local+"������\n";
	

else 	output="��"+ob_list[i]->query("name")+"���ƺ���ĳ���ط���"+local+"����,������Ϊ��"+HIW""+ck+""+NOR"�ĵط���\n";


if (dir2[1]=="jiangling")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"����ǵ�"NOR+local+"������\n";
}

if (dir2[1]=="yueyang")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�����ǵ�"NOR+local+"������\n";	
}

if (dir2[1]=="qilian")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"����ɽ��"NOR+local+"������\n";	
}

if (dir2[1]=="shouxihu")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"��������"NOR+local+"������\n";	
}

if (dir2[1]=="wuxi")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�����ǵ�"NOR+local+"������\n";	
}

if (dir2[1]=="yixing")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���˳ǵ�"NOR+local+"������\n";	
}
if (dir2[1]=="taiwan")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"̨�������"NOR+local+"������\n";	
}
if (dir2[1]=="nanyang")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"����������"NOR+local+"������\n";	
}
if (dir2[1]=="nanshaolin")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�����ֵ�����"NOR+local+"������\n";	
}

if (dir2[1]=="cangzhou")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���ݵ�����"NOR+local+"������\n";	
}

if (dir2[1]=="tanggu")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�����ǵ�����"NOR+local+"������\n";	
}

if (dir2[1]=="yunhe")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�������˺ӵ�"NOR+local+"������\n";	
}

if (dir2[1]=="hainan")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���ϵ���"NOR+local+"������\n";	
}

if (dir2[1]=="jindezheng")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�������"NOR+local+"������\n";	
}

if (dir2[1]=="yandang")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�㵴ɽ��"NOR+local+"������\n";	
}

if (dir2[1]=="jinling")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"����ǵ�"NOR+local+"������\n";	
}

if (dir2[1]=="sandboy")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"����ũ���"NOR+local+"������\n";	
}

if (dir2[1]=="huangshan")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"��ɽ��"NOR+local+"������\n";	
}

if (dir2[1]=="yubifeng")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"��ʷ��"NOR+local+"������\n";	
}

if (dir2[1]=="quanzhouchen")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"Ȫ�ݳ��ڵ�"NOR+local+"������\n";	
}

if (dir2[1]=="qingzh")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"��ظ�ԭ����"NOR+local+"������\n";	
}

if (dir2[1]=="changbaishan" || dir2[1]=="gaoli")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���� ����ɽ������"NOR+local+"������\n";	
}

if (dir2[1]=="annan")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���� ������"NOR+local+"������\n";	
}

if (dir2[1]=="taiyuan")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"̫ԭ ������"NOR+local+"������\n";	
}

if (dir2[1]=="hefei")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�Ϸ� ������"NOR+local+"������\n";	
}

if (dir2[1]=="jiujiang")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�Ž� ������"NOR+local+"������\n";	
}

if (dir2[1]=="baling")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���� ������"NOR+local+"������\n";	
}

if (dir2[1]=="xinjiang")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�½� ������"NOR+local+"������\n";	
}
if (dir2[1]=="dingxiang")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���� ������"NOR+local+"������\n";	
}
if (dir2[1]=="suiye")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"��Ҷ ������"NOR+local+"������\n";	
}


if (dir2[1]=="mayi")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���ر߽� ������"NOR+local+"������\n";	
}
if (dir2[1]=="xuzhou")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���ݳ� ������"NOR+local+"������\n";	
}
if (dir2[1]=="jinan")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���ϳ� ������"NOR+local+"������\n";	
}
if (dir2[1]=="guizhou")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"������ ������"NOR+local+"������\n";	
}

if (dir2[1]=="nanchang")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"�ϲ��� ������"NOR+local+"������\n";	
}


if (dir2[1]=="changsha")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"��ɳ�� ������"NOR+local+"������\n";	
}


if (dir2[1]=="zhongzhou")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���ݳ� ������"NOR+local+"������\n";	
}

if (dir2[1]=="xizang" || dir2[1]=="zangbei")  
{
	output="��"+ob_list[i]->query("name")+"���ƺ���"+HIY"���ػ�ر�������"NOR+local+"������\n";	
}
if (wizardp(this_player()))
{
outputt +="��"+ob_list[i]->query("name")+"����"+dir2[1]+"��"+local+"����,������Ϊ��"+HIW""+ck+""+NOR"�ĵط���\n";
output=outputt;
}
	return output;

                }

                }

	}

                return "ȷ������"+strr+"�Ĵ��λ��.\n";



}

varargs int already_spreaded(string str,int hard)

{

        object ob,*ob_list;

        int i;

        if(!str) return 0;

	if(hard)

	{

        ob_list = children(str);

        for(i=0; i<sizeof(ob_list); i++) {

                ob=find_env(ob_list[i]);

                if(ob)

		{ ob_list[i]->move(VOID_OB);

		 destruct(ob_list[i]);
		}

	}

	return 0;

	}

	else

	{

	if(!str) return 0;

	ob_list = children(str);

	for(i=0; i<sizeof(ob_list); i++) {

                ob=find_env(ob_list[i]);

                if(ob)

			return 1;

	}

	return 0;

	}

}

object find_env(object ob)

{

        while(ob)

        { ob=environment(ob);
          if(ob)
          if(ob->query("short") ) return ob;

     //   else ob=environment(ob);

        }

        return ob;

}

object find_book(object ob)

{

        while(ob)

        {

          if(ob->query("short") ) return ob;
//        if(ob->query("exits") ) return ob;
     
        else ob=environment(ob);

        }

        return ob;

}
mapping *read_table(string file)

{

	string *line, *field, *format;

	mapping *data;

	int i, rn, fn;



	line = explode(read_file(file), "\n");

	data = ({});

	for(i=0; i<sizeof(line); i++) {

		if( line[i]=="" || line[i][0]=='#' ) continue;

		if( !pointerp(field) ) {

			field = explode( line[i], ":" );

			continue;

		}

		if( !pointerp(format) ) {

			format = explode( line[i], ":" );

			continue;

		}

		break;

	}



	for( rn = 0, fn = 0; i<sizeof(line); i++) {

		if( line[i]=="" || line[i][0]=='#' ) continue;

		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });

		sscanf( line[i], format[fn], data[rn][field[fn]] );

		fn = (++fn) % sizeof(field);

		if( !fn ) ++rn;

	}

	return data;

}

void big_reward(object me, object who, object item)

{

	tell_object(me,"�����У���\n");

}



void execute_accept_object(object me, object who, object item)

{

	who->accept_object(me,item);

}

