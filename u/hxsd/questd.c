//Heart of fy3 -- Tie
//#pragma optimize all
mapping *quests;
mapping *read_table(string file);
string *roomlines;
varargs void init_dynamic_quest(int hard);
varargs int spread_quest(mapping one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
string dyn_quest_list();
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8
#include <ansi.h>
string locate_obj(string str);
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
	quest = quest_item->query("dynamic_quest");
	if(base_name(who) != quest["owner_name"]) return 0;
        exp =200+random(300);
        pot = exp/7;
        score = random(10)+1;
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
	if( !undefinedp(quest["fin_func"]))
	call_other(this_object(),quest["fin_func"],me,who,quest_item);
	if(quest_item)
	destruct(quest_item);destruct(present("xdshi",me));
	tell_object(me,HIW"�����ϵ�"+HIR+"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"HIW"��������һ����ʧ�ˡ�\n"NOR);
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
	object obj0,obj1,obj2,obj3;
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
	if(sizeof(target)) cur_obj = target[random(sizeof(target))];
	if(cur_obj)
	{
	tar = new(quest["file_name"]);
	tar->set("value",0);
	tar->set("dynamic_quest",quest);
	tar->move(cur_obj);		
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
	output += sprintf("%s��%s��%s��\n",owner->query("name"),item->query("name"),item->query("id"));
	else
	output = sprintf("%s��%s��%s��\n",owner->query("name"),item->query("name"),item->query("id")) + output;
	}
	else
	{
	if(random(2))
	output += sprintf("%s��%s��%s��������ɡ�\n",owner->query("name"),item->query("name"),item->query("id"));
	else
	output = sprintf("%s��%s��%s��������ɡ�\n",owner->query("name"),item->query("name"),item->query("id")) + output;
	}
	}
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
        object ob, tmpobj,where, *ob_list;
        object item,room;
        string output,dis,alt,dir;
        int i;
        int x,y,z,x0,y0,z0;
        int realdis;
	 mixed map;
        int tmp;
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
                ob=find_env(ob_list[i]);
                this_player()->add("jing",-5);
                if(ob)
                {
                map=values(ob->query("exits"));
                map=values(map[random(sizeof(map))]->query("exits"));//add by zzz for random locate
       if (ob->query("outdoors")=="baituo")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڰ���ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="binghuodao")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڱ��𵺵�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="city")  
	output="��"+ob_list[i]->query("name")+"���ƺ������ݵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="yangzhou")  
	output="��"+ob_list[i]->query("name")+"���ƺ������ݽ����"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="city2")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ھ��ǵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="chengdu") 
	output="��"+ob_list[i]->query("name")+"���ƺ��ڳɶ���"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="changan")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڳ����ǵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="dali")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڴ����"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="emei")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڶ�üɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="foshan")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڷ�ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="gaibang")  
	output="��"+ob_list[i]->query("name")+"���ƺ���ؤ���"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="gaochang")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڸ߲���"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="guanwai")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڹ����"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="guiyun")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڹ���ׯ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="gumu")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڹ�Ĺ�ɵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="hangzhou")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ں��ݵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="heimuya")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ں�ľ�µ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="hengshan")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ں�ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="henshan")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ں�ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="huanggon")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڻʹ���"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="huanghe")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڻƺӾ�����"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="xx")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڻ�ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="jinshe")  
	output="��"+ob_list[i]->query("name")+"���ƺ��ڽ���ɽ����"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="lingjiu")  
	output="��"+ob_list[i]->query("name")+"���ƺ������չ���"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="lingzhou")  
	output="��"+ob_list[i]->query("name")+"���ƺ������޵�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="meizhuang")  
	output="��"+ob_list[i]->query("name")+"���ƺ���÷ׯ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="mingjiao")  
	output="��"+ob_list[i]->query("name")+"���ƺ������̵�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="qingcheng")  
	output="��"+ob_list[i]->query("name")+"���ƺ������ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="quanzhen")  
	output="��"+ob_list[i]->query("name")+"���ƺ�����������"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="quanzhou")  
	output="��"+ob_list[i]->query("name")+"���ƺ���Ȫ�޵�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="shaolin")  
	output="��"+ob_list[i]->query("name")+"���ƺ��������µ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="shenlong")  
	output="��"+ob_list[i]->query("name")+"���ƺ�����������"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="songshan")  
	output="��"+ob_list[i]->query("name")+"���ƺ�����ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="suzhou")  
	output="��"+ob_list[i]->query("name")+"���ƺ������ݵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="taishan")  
	output="��"+ob_list[i]->query("name")+"���ƺ���̩ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="taohua")  
	output="��"+ob_list[i]->query("name")+"���ƺ����һ�����"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="tianlongsi")  
	output="��"+ob_list[i]->query("name")+"���ƺ��������µ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="wanjiegu")  
	output="��"+ob_list[i]->query("name")+"���ƺ�����ٹȵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="wudang")  
	output="��"+ob_list[i]->query("name")+"���ƺ����䵱ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="xiakedao")  
	output="��"+ob_list[i]->query("name")+"���ƺ������͵���"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="xiangyang")  
	output="��"+ob_list[i]->query("name")+"���ƺ��������ǵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="xiaoyao")  
	output="��"+ob_list[i]->query("name")+"���ƺ�����ң�ֵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="xingxiuhai")  
	output="��"+ob_list[i]->query("name")+"���ƺ������޺���"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="xueshan")  
	output="��"+ob_list[i]->query("name")+"���ƺ���ѩɽ�µ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="mr")  
	output="��"+ob_list[i]->query("name")+"���ƺ���Ľ�����ҵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="kunlun")  
	output="��"+ob_list[i]->query("name")+"���ƺ�������ɽ��"+map[random(sizeof(map))]->query("short")+"������\n";
else if (ob->query("outdoors")=="tiezhang")  
	output="��"+ob_list[i]->query("name")+"���ƺ��������ŵ�"+map[random(sizeof(map))]->query("short")+"������\n";
else 	output="��"+ob_list[i]->query("name")+"���ƺ���ĳ���ط���"+map[random(sizeof(map))]->query("short")+"������\n";
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
        {
        if(ob->query("exits") ) return ob;
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
