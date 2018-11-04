#include <ansi.h>

inherit NPC;
#include "action.h"
#include "party.h"
mapping *menpai=({
(["mp":"wudang",]),
(["mp":"lingjiu",]),
(["mp":"taohua",]),
(["mp":"tiandihui",]),
(["mp":"mingjiao",]),
(["mp":"gumu",]),
(["mp":"huashan",]),
(["mp":"gaibang",]),
(["mp":"quanzhen",]),
(["mp":"dali",]),
(["mp":"tiezhang",]),
(["mp":"murong",]),
(["mp":"kunlun",]),
(["mp":"lingxiao",]),
(["mp":"wdjiao",]),
(["mp":"jiuyin",]),
(["mp":"noname",])
});
string *ns = ({	"force",
		"dodge",
		"parry",
		"unarmed",
		"strike",
		"cuff",
		"finger",
		"claw",
		"hand",
		"leg",
		"sword",
		"blade",
		"whip",
		"hammer",
		"staff",
		"axe",
		"literate",
		"shenzhao-jing",
});
string *cmds = ({"wield", "unwield", "wear", "remove", "enable", "jifa", "prepare", "bei", "exert",
"yun", "perform", "yong", "enforce", "jiali"});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["id":"zuizui","title":"����֮��","name":"׺׺",]),
(["id":"zhword","title":"��Զ��Ư����","name":"����",]),
(["id":"danyingzi","title":"���������","name":"������",]),
(["id":"fox","title":"ᰵ�ð����","name":"����",]),
(["id":"cash","title":"�׵�̽���","name":"��Ʊ",]),
(["id":"fen","title":"���޶���","name":"����",]),
(["id":"lting","title":"����Ůɮ��","name":"�L���滨","sex":1,]),
(["id":"shazi","title":"��֮ͫ��","name":"���",]),
(["id":"hotwing","title":"ħ��ս��","name":"������ʹ",]),
(["id":"lavender","title":"ħ��֮��ò","name":"޹�²�","sex":1,]),
(["id":"bakangel","title":"ʥ֮Ů��ʿ","name":"����ʹ","sex":1,]),
(["id":"rains","title":"�缲����","name":"СС��ʿ",]),
(["id":"guipu","title":"�������","name":"����",]),
(["id":"flyt","title":"ͫ��Ů��ʿ","name":"����","sex":1,]),
(["id":"qing","title":"����֮��ò","name":"����Ũ","sex":1,]),
(["id":"sos","title":"����֮ӥ","name":"�ɷɷɷɻ�",]),
(["id":"dings","title":"��֮����","name":"Ѽ��",]),
(["id":"damenly","title":"�������","name":"ȱ�¾�ʿ",]),
(["id":"Qlbl","title":"�ɫ���","name":"��竹���",]),
(["id":"xbd","title":"ħ֮̽����","name":"С����",]),
(["id":"game","title":"��֮����","name":"��Ϸ",]),
(["id":"amei","title":"����֮��","name":"ǧɽĺѩ","sex":1,]),
(["id":"zbabla","title":"����֮��","name":"��ң����",]),
(["id":"lunar","title":"��֮Ů��","name":"ѩ÷","sex":1,]),
(["id":"yoyo","title":"����ħ��֮��","name":"����",]),
(["id":"snowfly","title":"��������","name":"ѩ��Ʈ","sex":1,]),
(["id":"wto","title":"��ħ�����","name":"������ŷ",]),
(["id":"hadis","title":"����֮��","name":"����˹",]),
(["id":"angel","title":"���ߵ��ػ���","name":"糴嵶��",]),
(["id":"zohu","title":"���صĹ��","name":"����",]),
(["id":"dfei","title":"�������","name":"���",]),
(["id":"bakangel","title":"��ħ�Ĵ���Ů","name":"����ʹ","sex":1,]),
(["id":"woodtian","title":"�������","name":"�Ұ�����Ů",]),
(["id":"kjhojin","title":"��ħ������","name":"ˮ���","sex":1,]),
(["id":"thill","title":"�����ʹ��","name":"������",]),
(["id":"dido","title":"ʥͫ","name":"������",]),
(["id":"cold","title":"��ʹ����","name":"����",]),
(["id":"scan","title":"��һ���׸���","name":"��Ӣ����",]),
(["id":"lubinh","title":"�������Ĳ�","name":"С����",]),
(["id":"lightning","title":"��ħ��С͵","name":"����",]),
(["id":"xiaomei","title":"Ů���΢Ц","name":"С��","sex":1,]),
(["id":"dldi","title":"��ɫצ��","name":"�����幤",]),
(["id":"mafan","title":"����ָ֮","name":"�鷳",]),
(["id":"hailoo","title":"����ħŮ","name":"��������","sex":1,]),
(["id":"bingxueer","title":"ʥħŮ","name":"��ѩ��","sex":1,]),
(["id":"caree","title":"����Ů��","name":"��������","sex":1,]),
(["id":"damenl","title":"�ɫ��ʿ","name":"��Ǯ�뷢��",]),
(["id":"xiaotian","title":"���з������ë","name":"Х��",]),
(["id":"waaas","title":"��Ⱦħ��","name":"�ض�","sex":1,]),
(["id":"dbabla","title":"������","name":"��а",]),
(["id":"lyf","title":"��Ӱ��Ů","name":"������","sex":1,]),
(["id":"loveyqh","title":"ʥ֮ħ��ʦ","name":"ˮ��",]),
(["id":"lovefox","title":"��Ů��","name":"����","sex":1,]),
(["id":"linda","title":"��֮Ů��ʿ","name":"�׾���","sex":1,]),
(["id":"lindy","title":"����֮��","name":"Ľ����","sex":1,]),
(["id":"lexy","title":"Ư������Ҷ","name":"����ң",]),
(["id":"laiyinhate","title":"��������","name":"�������",]),
(["id":"yzx","title":"��Զ������","name":"��������",]),
(["id":"xnh","title":"�컢","name":"����",]),
(["id":"xjhjin","title":"����Ů��","name":"����","sex":1,]),
(["id":"xiaoxuan","title":"������΢Ц","name":"������",]),
(["id":"xdb","title":"����սʿ","name":"ѩ����",]),
(["id":"wumi","title":"��֮��","name":"����",]),
(["id":"wukong","title":"����սʿ","name":"�����ʥ",]),
(["id":"wishluck","title":"����֮��","name":"С����","sex":1,]),
(["id":"winco","title":"��������","name":"�Ʒ�",]),
(["id":"wanxia","title":"��ն����","name":"��ϼ","sex":1,]),
(["id":"wanghu","title":"��ᰵ�����","name":"�������",]),
(["id":"waaa","title":"��������","name":"����",]),
(["id":"myth","title":"�ǻݵ�������","name":"Ľ�ݲ�",]),
(["id":"vov","title":"��·�Ĵǵ�","name":"����",]),
(["id":"tyywl","title":"����֮��","name":"��ҰԴ����",]),
(["id":"ttss","title":"��װ����","name":"������","sex":1,]),
(["id":"tianjun","title":"�ž�֮����","name":"����",]),
(["id":"tcl","title":"а��","name":"����",]),
(["id":"taotao","title":"��ħ֮����","name":"OhMyGod",]),
(["id":"sug","title":"��ϸ��ָ��","name":"�����","sex":1,]),
(["id":"sprite","title":"����ħ��","name":"С����",]),
(["id":"sony","title":"�ڸּ���","name":"Ե��",]),
(["id":"snq","title":"��ʵ��̽����","name":"СС",]),
(["id":"snow","title":"������֮Դ","name":"������ѩ","sex":1,]),
(["id":"smj","title":"������֮��","name":"������",]),
(["id":"smile","title":"����֮��","name":"����",]),
(["id":"sjmoxj","title":"�������","name":"����ʫ��",]),
(["id":"siren","title":"а��ʹ��","name":"���",]),
(["id":"shuanger","title":"ˮӳ֮��","name":"����˪","sex":1,]),
(["id":"shanc","title":"���ɵ���Ů","name":"����","sex":1,]),
(["id":"sgy","title":"��ʹͽ","name":"С��",]),
(["id":"scare","title":"������������","name":"Ц����",]),
(["id":"rui","title":"����֮ħ�ٹ���","name":"��ѩƮ��","sex":1,]),
(["id":"quanjia","title":"����Ů","name":"Ȫ��","sex":1,]),
(["id":"qkry","title":"�����","name":"Ǭ������",]),
(["id":"qiuqiu","title":"��ս�پ�","name":"����",]),
(["id":"qazqaz","title":"����ʿ","name":"������",]),
(["id":"pxf","title":"����ı���","name":"ľ��",]),
(["id":"pcgame","title":"����֮ս��","name":"����",]),
(["id":"papaya","title":"�ƻ���","name":"����",]),
(["id":"orange","title":"����Ů��","name":"����","sex":1,]),
(["id":"ooo","title":"�����Ͻ�","name":"���֮��",]),
(["id":"only","title":"�����Ĳ��ܶ�ʿ","name":"�����о�",]),
(["id":"nvnv","title":"��֮��ʿ","name":"����",]),
(["id":"npc","title":"���Ĵ�����","name":"С����","sex":1,]),
(["id":"name","title":"аսʿ","name":"ֱ����",]),
(["id":"mzlm","title":"�Ҹ�ʹ��","name":"����",]),
(["id":"marine","title":"������������","name":"����Ź�",]),
(["id":"means","title":"����������","name":"��˼",]),
(["id":"miean","title":"�޹�Ե�ָ��","name":"����",]),
(["id":"mingyang","title":"��ħ��ʹ��","name":"����",]),
(["id":"mini","title":"��ɫħ��","name":"����",]),
(["id":"mmm","title":"����֮ӥ","name":"�Ž�һ��",]),
(["id":"mrf","title":"���ڽֵ�֧����","name":"Ľ�ݷ�",]),
(["id":"mryh","title":"�ž��İ�ɱ��","name":"�ƻ�",]),
(["id":"myboy","title":"�����","name":"�������",]),
(["id":"mygirl","title":"�ڹ�֩��","name":"����","sex":1,]),
(["id":"lang","title":"��ħ���","name":"�˷���",]),
(["id":"langer","title":"����֮ͷ��","name":"����",]),
(["id":"legs","title":"ħ��Ů��ʿ","name":"��������","sex":1,]),
(["id":"lbxx","title":"��ħ��ʹ��","name":"����С��",]),
(["id":"lengxin","title":"��֮��ʿ","name":"����",]),
(["id":"ling","title":"��ɫŮ��ʦ","name":"���","sex":1,]),
(["id":"ljgbook","title":"��������","name":"����","sex":1,]),
(["id":"lkdd","title":"����սʿ","name":"�ٱ��Ǿ�",]),
(["id":"kara","title":"�û�֮Ůħ��ʦ","name":"����","sex":1,]),
(["id":"keeny","title":"������","name":"����",]),
(["id":"keyboard","title":"��֮����","name":"����",]),
(["id":"kgb","title":"��Զ��(ͨ����)","name":"����С��",]),
(["id":"killman","title":"�ɻ�С��","name":"�����Ǯ��",]),
(["id":"jad","title":"���ȵ���","name":"����",]),
(["id":"jianxin","title":"������ʦ","name":"��̫",]),
(["id":"jxy","title":"����֮����","name":"Ф��",]),
(["id":"icefox","title":"���ߵ�����","name":"����",]),
(["id":"hadis","title":"�������","name":"����˹",]),
(["id":"hechuan","title":"��ɫ����","name":"��Ӣ��",]),
(["id":"hehaia","title":"����ʹ��","name":"�κ���",]),
(["id":"himura","title":"���鷨ʦ","name":"����",]),
(["id":"honda","title":"���˽�ʿ","name":"����",]),
(["id":"huakai","title":"С����","name":"���仨��",]),
(["id":"hylijun","title":"������","name":"����è",]),
(["id":"hxt","title":"����սʿ","name":"��ֽһ��",]),
(["id":"huihui","title":"����ħ��ʹ","name":"��Ľ",]),
(["id":"gameking","title":"�����ʿ","name":"��Ϸ֮��",]),
(["id":"gaoc","title":"���鳤��","name":"�߲�",]),
(["id":"gmxy","title":"����ɱ��","name":"����",]),
(["id":"grape","title":"�ڰ�����","name":"�̶���",]),
(["id":"green","title":"ɱ�ֹ���ʹ��","name":"��Ҷ��",]),
(["id":"fadai","title":"��Ԫ��ʹ��","name":"����",]),
(["id":"fall","title":"ʥ��֮����","name":"������","sex":1,]),
(["id":"fff","title":"��Ԫ��ʹ��","name":"����",]),
(["id":"ffs","title":"��Ԫ��ʹ��","name":"��а",]),
(["id":"fgy","title":"ˮԪ��ʹ��","name":"������",]),
(["id":"flower","title":"��֮Ů��","name":"������","sex":1,]),
(["id":"foryou","title":"����Ů����","name":"��ʫ","sex":1,]),
(["id":"foxzzz","title":"�ڰ�����Ů","name":"ѩ��","sex":1,]),
(["id":"frfr","title":"ħ����ʿ","name":"����",]),
(["id":"ftoiloveyou","title":"��֮��ʦ","name":"ѩ����ʥ",]),
(["id":"fury","title":"��ɫ����ʦ","name":"��ƽ��",]),
(["id":"fusheng","title":"�ƻ���֮��ʦ","name":"��.����",]),
(["id":"eddie","title":"����֮ͫ","name":"������","sex":1,]),
(["id":"ehuan","title":"ħ��Ůսʿ","name":"����","sex":1,]),
(["id":"enjoy","title":"��������","name":"����",]),
(["id":"eric","title":"ʥ��ʿ","name":"����",]),
(["id":"dairun","title":"ħ��ʿ","name":"����",]),
(["id":"dali","title":"����ɱ��","name":"����",]),
(["id":"datank","title":"�ٹ�֮��ʿ","name":"��̹��",]),
(["id":"dhxy","title":"������ʿ","name":"������",]),
(["id":"digu","title":"��֮����","name":"ͯ��ϱ",]),
(["id":"dldi","title":"��ʿ��","name":"�����幤",]),
(["id":"dodo","title":"��ʿͳʦ","name":"ûƷ����",]),
(["id":"donkey","title":"������ʿ","name":"¿��",]),
(["id":"duly","title":"����ʿ","name":"����",]),
(["id":"caiyi","title":"��Ѫ��Ů����","name":"����","sex":1,]),
(["id":"camin","title":"�޳ܺ�����","name":"Ц��",]),
(["id":"chaosheng","title":"ʥ��֮Ұ����","name":"����",]),
(["id":"cloud","title":"Ұ����֮��","name":"����",]),
(["id":"com","title":"���ǵ�Ұ����","name":"���",]),
(["id":"cutlove","title":"Ұ���˷�ʦ","name":"�ᵶ",]),
(["id":"baggio","title":"Ұ��֮ħ��ʹ","name":"��ԯ��",]),
(["id":"baishi","title":"��Ѩ����֮ĸ","name":"������","sex":1,]),
(["id":"banana","title":"�������","name":"�㽶",]),
(["id":"baoer","title":"����","name":"�ֱ���",]),
(["id":"battlee","title":"ʳ��ħŮ��","name":"Ѧ��","sex":1,]),
(["id":"bear","title":"ľ����","name":"Ц��",]),
(["id":"bee","title":"��Ůţͷ��","name":"Ů����","sex":1,]),
(["id":"bihu","title":"������","name":"�ڻ�",]),
(["id":"biluo","title":"��ɫ֮����","name":"����������","sex":1,]),
(["id":"bird","title":"�����˹���","name":"����","sex":1,]),
(["id":"bingxueer","title":"�ɰ���ʳʬ��","name":"��ѩ��","sex":1,]),
(["id":"bmr","title":"����֮���","name":"ѩ��","sex":1,]),
(["id":"budai","title":"Ԫ����","name":"������ȥ",]),
(["id":"bullet","title":"ħ����ʿ","name":"С��",]),
(["id":"admire","title":"ʳ��������","name":"����",]),
(["id":"aka","title":"�ڰ�����","name":"����",]),
(["id":"akan","title":"ħ������","name":"Ī������",]),
(["id":"amejio","title":"����ħ����Ů","name":"���","sex":1,]),
(["id":"amy","title":"��ҹ֮Ůɱ��","name":"����","sex":1,]),
(["id":"ant","title":"����֮��ħ��ʿ","name":"����","sex":1,]),
(["id":"anran","title":"ħ��˾��","name":"������Ȼ",]),
(["id":"aoe","title":"ħ�峤","name":"�ɰ�",]),
(["id":"axax","title":"ħ��ʹָ�ӹ�","name":"����",])
});
void random_chat();
mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);


void create()
{
	mapping npc,mp,j;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
	mp=menpai[random(sizeof(menpai))];
	j=ps[random(sizeof(ps))];
ob=this_object();
	k=random(17);
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);
set("vendetta/authority",1);
	set("age",20+random(30));
        set("per",20+random(30));
if (sex)
set("gender", "Ů��" );
else set("gender", "����" );
	set("combat_exp",3000000+random(20000000));
	set_temp("apply/attack",30);
	set_temp("apply/defense",30);
	set_temp("apply/armor",250);
	set_temp("apply/damage",150);
	set("max_force",2000);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
set("no_get",1);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
b=4000+random(4000);
a=6000+random(9000);
d=30+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("neili",a);
        set("max_neili",a);
	this_object()->set("party",ps[k]["party"]);
	this_object()->set_skills(ps[k]["skills"]);
	this_object()->set_skill_map(ps[k]["skill_map"]);
	this_object()->set_skill_prepare(ps[k]["skill_prepare"]);
        i=200+random(500);
        e=200+random(500);
	for (k = 0; k < sizeof(ns); k++)
		this_object()->set_skill(ns[k], i);

		this_object()->set_skill("literate",i);
        this_object()->set_skill("shenzhao-jing",e);
if (mapp(skill_status = this_object()->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = this_object()->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
this_object()->set_skill(sname[i],e);//ɾ���Լ����й���
}
        this_object()->change_combat_mode();
set("chat_chance_combat", 100);
set("chat_msg_combat", get_auto_actions("perform"));
change_combat_mode(ob, 1);
        set("chat_chance", 20);
        set("chat_msg", ({
 (: random_move :)
//                (: command, "exert powerup" :),
//                (:random_chat:),
        }) );
        
f=1+random(8);        
	setup();

	if (ob->query("gender")=="Ů��")
	{
	carry_object("/clone/cloth/female"+f+"-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	}
else {
	carry_object("/clone/cloth/male"+f+"-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
}        
        if (stringp(ob->query_skill_mapped("sword"))) 
	carry_object(__DIR__"weapon/sword")->wield();
	if (stringp(ob->query_skill_mapped("blade"))) 
	carry_object(__DIR__"weapon/dao")->wield();
	if (stringp(ob->query_skill_mapped("whip"))) 
	carry_object(__DIR__"weapon/bian")->wield();
	if (stringp(ob->query_skill_mapped("hammer"))) 
	carry_object(__DIR__"weapon/hammer")->wield();
	if (stringp(ob->query_skill_mapped("staff"))) 
	carry_object(__DIR__"weapon/ban")->wield();
	if (stringp(ob->query_skill_mapped("axe"))) 
	carry_object(__DIR__"weapon/axe")->wield();

	add_money("silver",50+random(50));
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
		set("chat_chance_combat", 100);
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
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		return;
	}
	set("combat_mode", mode);
//	me->set("guard/status/combat_mode", mode);
}

void random_chat()
{
  string *e,str="";
   int i;
   object npc,*inv;
if (!environment(this_object()))
   return;
   inv=all_inventory(environment(this_object()));
	if(!sizeof(inv))	return;
 
   e = sort_array(EMOTE_D->query_all_emote(), 1);
   str=e[random(sizeof(e))];
   command(str+" "+inv[random(sizeof(inv))]->query("id"));
   set("answer",str);  
   return;
}

int chat()
{
	int i, ratio, chance, rnd, flag = 0;
	string *msg, *emotes, cmd;
	object *inv, *killer;

	if (!is_busy() 
	&& living(this_object())
	&& environment(this_object()) )
	{
		if (arrayp(msg = get_auto_actions("powerup")))
			for (i = 0; i < sizeof(msg); i++)
				if (functionp(msg[i]))
					evaluate(msg[i]);
	}


	if (query("neili") > 100 && query("max_neili") > 200 && !is_busy()
	&& living(this_object())
	&& environment(this_object()) 
	) {
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

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( query_temp("is_unconcious") ) return 0;
		if(!living(this_object()) ) return 0;
		if(!environment(this_object())  ) return 0;

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


void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
if (!ob->is_fighting()) 
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
if (!ob->is_fighting()) 
ob->start_busy(1);
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        call_out("check",0);
        }
}
void die()
{
        object corpse, killer;
        int i;
        string skill;
        object jla , jlb;

        if( !living(this_object()) ) revive(1);
        if( wizardp(this_object()) && query("env/immortal") ) return;

        this_object()->clear_condition();

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(killer = query_temp("last_damage_from")) ) {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
        }

if (!killer) return;
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
killer->remove_all_killer();
        if (userp(killer) )
        {
             jla=new("/clone/box/gbox");
jla->move(environment(this_object()));
        this_object()->remove_all_killer();
message_vision("$N�ҵ���һ�����䡣\n",killer);
        all_inventory(environment())->remove_killer(this_object());
        destruct(this_object());
}
        destruct(this_object());
}