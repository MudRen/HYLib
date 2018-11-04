#include <ansi.h>

inherit NPC;
#include "action2.h"
#include "party2.h"
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
(["mp":"baituo",]),
(["mp":"emei",]),
(["mp":"xiaoyao",]),		
(["mp":"mizong",]),
(["mp":"xingxiu",]),
(["mp":"feitian",]),
(["mp":"shenlong",]),
(["mp":"tangmen",]),		
(["mp":"riyue",]),
(["mp":"mizong1",]),
(["mp":"shaolin",]),
(["mp":"riyue1",]),
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
(["id":"zuizui","title":"ؤ��Ŵ�����","name":"׺׺ ",]),
(["id":"zhword","title":"������������","name":"���� ",]),
(["id":"danyingzi","title":"����BUG","name":"������ ",]),
(["id":"fox","title":"������","name":"���� ",]),
(["id":"cash","title":"���������һ","name":"��Ʊ ",]),
(["id":"fen","title":"����ڰ���ʹ","name":"���� ",]),
(["id":"lting","title":"�����滨���滨����","name":"�L���滨","sex":1,]),
(["id":"shazi","title":"��������ϴ�","name":"��� ",]),
(["id":"hotwing","title":"�������������佫","name":"������ʹ ",]),
(["id":"lavender","title":"�������","name":"޹�²�","sex":1,]),
(["id":"bakangel","title":"���ŵ��ߴ�����","name":"����ʹ","sex":1,]),
(["id":"rains","title":"��ɽ�ɵ�ʮ��������","name":"СС��ʿ ",]),
(["id":"guipu","title":"������å����˭������","name":"���� ",]),
(["id":"flyt","title":"���۸����Ϲ���","name":"����","sex":1,]),
(["id":"qing","title":"���ϵ�һŮ��","name":"����Ũ","sex":1,]),
(["id":"sos","title":"������ͳ","name":"�ɷɷɷɻ� ",]),
(["id":"dings","title":"ֻ����������","name":"Ѽ�� ",]),
(["id":"damenly","title":"�Ҿ������ɱ�ɻ���һë����","name":"ȱ�¾�ʿ ",]),
(["id":"Qlbl","title":"�嶾�̳���","name":"��竹��� ",]),
(["id":"xbd","title":"�����һ","name":"С���� ",]),
(["id":"game","title":"Ī˼�����������Ҿ���ǰ���ޱ�","name":"��Ϸ ",]),
(["id":"amei","title":"�嶾�̳���","name":"ǧɽĺѩ","sex":1,]),
(["id":"zbabla","title":"�Ұ��汦��","name":"��ң���� ",]),
(["id":"lunar","title":"�һ����ڶ�������","name":"ѩ÷","sex":1,]),
(["id":"yoyo","title":"�һ����ڶ�������","name":"���� ",]),
(["id":"snowfly","title":"��Ҫ������һ��","name":"ѩ��Ʈ","sex":1,]),
(["id":"wto","title":"���ư��ʮ�������","name":"������ŷ ",]),
(["id":"hadis","title":"���ư��ʮ�������","name":"����˹ ",]),
(["id":"angel","title":"������������������ʮ�ߴ�������","name":"糴嵶�� ",]),
(["id":"zohu","title":"��˵���汻�״�����","name":"���� ",]),
(["id":"dfei","title":"��ң�ɻ���ʹ��","name":"��� ",]),
(["id":"bakangel","title":"���ŵ��ߴ�����","name":"����ʹ","sex":1,]),
(["id":"woodtian","title":"�ҵ�˧������ʮ����͵�����","name":"�Ұ�����Ů ",]),
(["id":"kjhojin","title":"���ŵ��ߴ�����","name":"ˮ���","sex":1,]),
(["id":"thill","title":"�����ڲ�����������","name":"������ ",]),
(["id":"dido","title":"��Ӱ���ťҥ���","name":"������ ",]),
(["id":"cold","title":"�����﷢��һ����","name":"���� ",]),
(["id":"scan","title":"����ͷ�ŵ���","name":"��Ӣ���� ",]),
(["id":"lubinh","title":"һ����ǰ��û���㣬Ҳû����","name":"С���� ",]),
(["id":"lightning","title":"�����ɵ���ʮ�������","name":"���� ",]),
(["id":"xiaomei","title":"�䵱�ɵڶ�������","name":"С��","sex":1,]),
(["id":"dldi","title":"�������������佫","name":"�����幤 ",]),
(["id":"mafan","title":"��ң�ɻ���ʹ��","name":"�鷳 ",]),
(["id":"hailoo","title":"ȫ��̵ڶ�������","name":"��������","sex":1,]),
(["id":"bingxueer","title":"�����Ľ��е���","name":"��ѩ��","sex":1,]),
(["id":"caree","title":"�����ŵ���������","name":"��������","sex":1,]),
(["id":"damenl","title":"����ͷ","name":"��Ǯ�뷢�� ",]),
(["id":"xiaotian","title":"ͨ������±�Х��͵�������","name":"Х�� ",]),
(["id":"waaas","title":"������һ������","name":"�ض�","sex":1,]),
(["id":"dbabla","title":"�嶾����","name":"��а ",]),
(["id":"lyf","title":"������·�㲻��ѽ","name":"������","sex":1,]),
(["id":"loveyqh","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"ˮ�� ",]),
(["id":"lovefox","title":"���ϸ�","name":"����","sex":1,]),
(["id":"linda","title":"���ã������Լ���ͦ����...","name":"�׾���","sex":1,]),
(["id":"lindy","title":"��֮��","name":"Ľ����","sex":1,]),
(["id":"lexy","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"����ң ",]),
(["id":"laiyinhate","title":"��Ӱ�����ų�","name":"������� ",]),
(["id":"yzx","title":"��һ���ķ���","name":"�������� ",]),
(["id":"xnh","title":"ѩɽ�����Ŵ����","name":"���� ",]),
(["id":"xjhjin","title":"��ң�ɵ���","name":"����","sex":1,]),
(["id":"xiaoxuan","title":"��ġ�sk�������ˣ�","name":"������ ",]),
(["id":"xdb","title":"��ɽ����","name":"ѩ���� ",]),
(["id":"wumi","title":"Ư���Ļ�����","name":"���� ",]),
(["id":"wukong","title":"����Ľ��","name":"�����ʥ ",]),
(["id":"wishluck","title":"�л�ʥ���⽻����","name":"С����","sex":1,]),
(["id":"winco","title":"������������֪�����������һ�","name":"�Ʒ� ",]),
(["id":"wanxia","title":"������±��޼۽�ˮԶɽ������","name":"��ϼ","sex":1,]),
(["id":"wanghu","title":"���м��˹�����һ�轣�����ķ�","name":"������� ",]),
(["id":"waaa","title":"��������Ϊ����","name":"���� ",]),
(["id":"myth","title":"����Ľ�ݵڶ�������","name":"Ľ�ݲ� ",]),
(["id":"vov","title":"õ����ʹ^_^","name":"���� ",]),
(["id":"tyywl","title":"����ɽ�ɵڶ�������","name":"��ҰԴ���� ",]),
(["id":"ttss","title":"�����޵��Ʋ���","name":"������","sex":1,]),
(["id":"tianjun","title":"���ϸ�ɽ������Ϫ��","name":"���� ",]),
(["id":"tcl","title":"ѩɽ���׼ҵ���","name":"���� ",]),
(["id":"taotao","title":"����ɽ�ɵڶ�������","name":"OhMyGod ",]),
(["id":"sug","title":"��ȹ����˭��Ů","name":"�����","sex":1,]),
(["id":"sprite","title":"��Ĺ�ɵ��Ĵ�����","name":"С���� ",]),
(["id":"sony","title":"�䵱�ɵڶ�������","name":"Ե�� ",]),
(["id":"snq","title":"�����ǳ���","name":"СС ",]),
(["id":"snow","title":"����Ϊ��","name":"������ѩ","sex":1,]),
(["id":"smj","title":"Ҫ exp","name":"������ ",]),
(["id":"smile","title":"������","name":"���� ",]),
(["id":"sjmoxj","title":"���","name":"����ʫ�� ",]),
(["id":"siren","title":"�������","name":"��� ",]),
(["id":"shuanger","title":"����С��Ů","name":"����˪","sex":1,]),
(["id":"shanc","title":"���չ��ڶ�������","name":"����","sex":1,]),
(["id":"sgy","title":"����","name":"С�� ",]),
(["id":"scare","title":"�Ұ� �³�","name":"Ц���� ",]),
(["id":"rui","title":"Amy�ľ��� ������","name":"��ѩƮ��","sex":1,]),
(["id":"quanjia","title":"������ˮ","name":"Ȫ��","sex":1,]),
(["id":"qkry","title":"��������ν����״�����","name":"Ǭ������ ",]),
(["id":"qiuqiu","title":"ؤ���ʮ�Ŵ�����","name":"���� ",]),
(["id":"qazqaz","title":"��������е���","name":"������ ",]),
(["id":"pxf","title":"~_______~","name":"ľ�� ",]),
(["id":"pcgame","title":"��ң�ɻ���ʹ��","name":"���� ",]),
(["id":"papaya","title":"�����԰����� ","name":"���� ",]),
(["id":"orange","title":"��ʦ��","name":"����","sex":1,]),
(["id":"ooo","title":"����HY��å�ϴ�","name":"���֮�� ",]),
(["id":"only","title":"����Թ�","name":"�����о� ",]),
(["id":"nvnv","title":"��һ��·ä","name":"���� ",]),
(["id":"npc","title":"ȫ��̵ڶ�������","name":"С����","sex":1,]),
(["id":"name","title":"��Ʒ����","name":"ֱ���� ",]),
(["id":"mzlm","title":"�������ֺ�","name":"���� ",]),
(["id":"marine","title":"��Ӱ���š����","name":"����Ź� ",]),
(["id":"means","title":"���ư��Ϲٰ�������","name":"��˼ ",]),
(["id":"miean","title":"���ε���û��Ϊ�����ؿ���Ǯ","name":"���� ",]),
(["id":"mingyang","title":"�һ��콣","name":"���� ",]),
(["id":"mini","title":"����μҵ�ʮ�ߴ�����","name":"���� ",]),
(["id":"mmm","title":"���������벻Ҫ��me˵��","name":"�Ž�һ�� ",]),
(["id":"mrf","title":"����Ľ�ݵ���������","name":"Ľ�ݷ� ",]),
(["id":"mryh","title":"���","name":"�ƻ� ",]),
(["id":"myboy","title":"���ա��ˡ隸��Ǯ","name":"������� ",]),
(["id":"mygirl","title":"С�¹���","name":"����","sex":1,]),
(["id":"lang","title":"�ԾƵ��裬��������","name":"�˷��� ",]),
(["id":"langer","title":"����������������","name":"���� ",]),
(["id":"legs","title":"ѡ������ ������ѡ","name":"��������","sex":1,]),
(["id":"lbxx","title":"ѩɽ���׼ҵ���","name":"����С�� ",]),
(["id":"lengxin","title":"��������ʦ","name":"���� ",]),
(["id":"ling","title":"ȫ��̵ڶ�������","name":"���","sex":1,]),
(["id":"ljgbook","title":" �������ʵ���������Ϊʲô������","name":"����","sex":1,]),
(["id":"lkdd","title":"������������������������ޱ�","name":"�ٱ��Ǿ� ",]),
(["id":"kara","title":"�����¸ɱ�","name":"����","sex":1,]),
(["id":"keeny","title":"����������Ҫ��������Ҳ������","name":"���� ",]),
(["id":"keyboard","title":"������ˡ���С�","name":"���� ",]),
(["id":"kgb","title":"��Զ��(ͨ����)","name":"����С�� ",]),
(["id":"killman","title":"�ɻ�С��","name":"�����Ǯ�� ",]),
(["id":"jad","title":"������ȸ¥֮�󵱼�","name":"���� ",]),
(["id":"jianxin","title":"��̫�ĵ���","name":"��̫ ",]),
(["id":"jxy","title":"��ɽ�ɵ�ʮ��������","name":"Ф�� ",]),
(["id":"icefox","title":"�þ�û����","name":"���� ",]),
(["id":"hadis","title":"���ư��ʮ�������","name":"����˹ ",]),
(["id":"hechuan","title":"ؤ��Ŵ�����","name":"��Ӣ�� ",]),
(["id":"hehaia","title":"����ʹ��","name":"�κ��� ",]),
(["id":"himura","title":"����μҵ�ʮ�ߴ�����","name":"���� ",]),
(["id":"honda","title":"��ӭ����www.fivekids.com","name":"���� ",]),
(["id":"huakai","title":"�����ǵ��ߴ�����","name":"���仨�� ",]),
(["id":"hylijun","title":"��ɽ�ɵ�ʮ��������","name":"����è ",]),
(["id":"hxt","title":"ʥ�����վ","name":"��ֽһ�� ",]),
(["id":"huihui","title":"�����ɵ���ʮ������","name":"��Ľ ",]),
(["id":"gameking","title":"�����ɾ����ڶ�������","name":"��Ϸ֮�� ",]),
(["id":"gaoc","title":"�߲��Թ�����","name":"�߲� ",]),
(["id":"gmxy","title":"����","name":"���� ",]),
(["id":"grape","title":"�մ�һ��¹����","name":"�̶��� ",]),
(["id":"green","title":"�����Թſ����","name":"��Ҷ�� ",]),
(["id":"fadai","title":"һ���˵�׷��","name":"���� ",]),
(["id":"fall","title":"�մ�һ��¹����","name":"������","sex":1,]),
(["id":"fff","title":"�����ĺ���","name":"���� ",]),
(["id":"ffs","title":"����","name":"��а ",]),
(["id":"fgy","title":"���ǽ�","name":"������ ",]),
(["id":"flower","title":"��������������ū","name":"������","sex":1,]),
(["id":"foryou","title":"Ϊ������","name":"��ʫ","sex":1,]),
(["id":"foxzzz","title":"�մ�һ��¹����","name":"ѩ��","sex":1,]),
(["id":"frfr","title":"ؤ��Ŵ�����","name":"���� ",]),
(["id":"ftoiloveyou","title":"wait me xue yitiantulong","name":"ѩ����ʥ ",]),
(["id":"fury","title":"һ�������������ҵ���ͷ��","name":"��ƽ�� ",]),
(["id":"fusheng","title":"����ɳ����ǧ����һЦ������","name":"��.���� ",]),
(["id":"eddie","title":"Amy�Ĵ��׾��������ų�","name":"������","sex":1,]),
(["id":"ehuan","title":"���� no look","name":"����","sex":1,]),
(["id":"enjoy","title":"ɫ��","name":"���� ",]),
(["id":"eric","title":"��ң�ɵ��Ĵ�����","name":"���� ",]),
(["id":"dairun","title":"�մ�һ��¹����","name":"���� ",]),
(["id":"dali","title":"�ܲ������","name":"���� ",]),
(["id":"datank","title":"�����ɵ���������","name":"��̹�� ",]),
(["id":"dhxy","title":"���ϴ����򡿱��Ϲ�Ѳ��ɱ��","name":"������ ",]),
(["id":"digu","title":"���ڹ��Ϻ����ӣ����Ͽ����","name":"ͯ��ϱ ",]),
(["id":"dldi","title":"�������������佫","name":"�����幤 ",]),
(["id":"dodo","title":"�»�Ұ��","name":"ûƷ���� ",]),
(["id":"donkey","title":"���ŵ��ߴ�����","name":"¿�� ",]),
(["id":"duly","title":"�ɻ�С��","name":"���� ",]),
(["id":"caiyi","title":"��ң�ɻ���ʹ��","name":"����","sex":1,]),
(["id":"camin","title":"�ɻ�С��","name":"Ц�� ",]),
(["id":"chaosheng","title":"Diablo12 www.love214.com","name":"���� ",]),
(["id":"cloud","title":"��ɽ�ɵ�ʮ��������","name":"���� ",]),
(["id":"com","title":"ǧ��˼��Ī����","name":"��� ",]),
(["id":"cutlove","title":"����ɽ�ɵڶ�������","name":"�ᵶ ",]),
(["id":"baggio","title":"����Ǳ��","name":"��ԯ�� ",]),
(["id":"baishi","title":"mely��רְ����","name":"������","sex":1,]),
(["id":"banana","title":"�����ɵ���������","name":"�㽶 ",]),
(["id":"baoer","title":"��ɽ�ɵ�ʮ��������","name":"�ֱ��� ",]),
(["id":"battlee","title":"����Ż���������ʦ��","name":"Ѧ��","sex":1,]),
(["id":"bear","title":"�ҹһ�������","name":"Ц�� ",]),
(["id":"bee","title":"��Ϸ����","name":"Ů����","sex":1,]),
(["id":"bihu","title":"С����","name":"�ڻ� ",]),
(["id":"biluo","title":"��ة��","name":"����������","sex":1,]),
(["id":"bird","title":"����ʹ��","name":"����","sex":1,]),
(["id":"bingxueer","title":"�����Ľ��е���","name":"��ѩ��","sex":1,]),
(["id":"bmr","title":"����","name":"ѩ��","sex":1,]),
(["id":"budai","title":"����Ľ�ݵ��Ĵ�����","name":"������ȥ ",]),
(["id":"bullet","title":"��Ҫ! ��Ҫ�� ��������","name":"С�� ",]),
(["id":"admire","title":"����������Ѱ����","name":"���� ",]),
(["id":"aka","title":"��������","name":"���� ",]),
(["id":"akan","title":"С����","name":"Ī������ ",]),
(["id":"amejio","title":"�һ����ڶ�������","name":"���","sex":1,]),
(["id":"amy","title":"�������µ�һ","name":"����","sex":1,]),
(["id":"ant","title":"��˭�ڶ���˵����������","name":"����","sex":1,]),
(["id":"anran","title":"��Ĺ֮����է��","name":"������Ȼ ",]),
(["id":"aoe","title":"�������� ���سɷ�","name":"�ɰ� ",]),
(["id":"axax","title":"Ը�������̳�� ��������ɨ�仨","name":"����",])
});
void random_chat();
mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);
int ask_job();
int ask_job2();
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
	k=random(29);
	//k=11;
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);
set("nick","����Ա");
set("vendetta/authority",1);
	set("age",20+random(30));
        set("per",20+random(30));
if (sex)
set("gender", "Ů��" );
else set("gender", "����" );
	set("combat_exp",3000000+random(20000000));
set("skill_public",1);
set("pubmaster",1);
	set_temp("apply/attack",50);
	set_temp("apply/defense",100);
	set_temp("apply/armor",550);
	set_temp("apply/damage",50);
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
b=2000+random(4000);
a=3000+random(9000);
d=20+random(60);
set("str",d);
set("dex",100);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("inquiry", ([
            "qixue" : (: ask_job() :),
            "��Ѫ" : (: ask_job() :),
            "�ο�" : (: ask_job2() :),
            "skill" : (: ask_job2() :),
        ]) );
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
set_skill("force", e);
        this_object()->change_combat_mode();
set("chat_chance_combat", 80);
set("chat_msg_combat", get_auto_actions("perform"));
change_combat_mode(ob, 1);
        
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
	if (stringp(ob->query_skill_mapped("throwing"))) 
	carry_object(__DIR__"weapon/throwing")->wield();

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
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		break;
	case 2:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform1"));
		set("jiali", (int)query_skill("force") / 2);
		break;
	case 3:
		set("chat_chance_combat", 80);
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
if (msg[i]) evaluate(msg[i]);
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


int do_copy(object me,int maxpot,int type)
{
        int j;
	mapping npc,mp;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
	mp=menpai[random(sizeof(menpai))];


        ob = this_object();
if (!me->query_skill("force"))
i=10;
else      i=me->query_skill("force",1);
//        if(type==1)
//		i = i - random(20);
//		else  
//	    i = i +10+ random(10);
//        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")*3/4));
        
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
        ob->set_skill("taiji-shengong", i);       
        ob->set_skill("wuxing-dun", i); 
//        ob->set_skill("shiren-jianfa", i); 
//        ob->set_skill("shiren-quanfa", i);         
        set_skill("taiji-shengong",i*1/2);
ob->set("jing",me->query("max_jing"));
ob->set("eff_jing",me->query("max_jing"));
ob->set("max_jing",me->query("max_jing"));
ob->set("qi",me->query("max_qi"));
ob->set("eff_qi",me->query("max_qi"));
ob->set("max_qi",me->query("max_qi"));
//ob->map_skill("unarmed", "shiren-quanfa");
//ob->map_skill("parry", "shiren-quanfa");
if (random(10)>8)
{
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
//        ob->set_skill("shiren-jianfa", i); 
//        ob->set_skill("shiren-quanfa", i);         
}
        ob->set("eff_jingli", me->query("eff_jingli")*1/2); 
        ob->set("jiali", i/6);
	ob->set("max_qi",  me->query("qi")*2/3); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("max_neili", me->query("max_neili")*2/3); 
        ob->set("jiali", i/10);
        if(type==3)
		{ob->set("max_qi",     me->query("qi")*2/3);
		 ob->set("max_neili",  me->query("max_neili")*2/3); 
		}
		if(type==2)
        ob->set("max_qi",     me->query("qi")*2/3); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi")*2/3);
        ob->set("neili",ob->query("max_neili")*2/3);
        ob->set("qi",me->query("max_qi"));
        ob->set("eff_qi",me->query("max_qi"));
        ob->set("max_qi",me->query("max_qi"));        
        ob->set("neili",me->query("max_neili"));
        ob->set("max_neili",me->query("max_neili"));
        ob->set("jing",me->query("max_jing"));
        ob->set("eff_jing",me->query("max_jing"));
        ob->set("max_jing",me->query("max_jing"));
ob->set("str",me->query("str"));
ob->set("dex",me->query("dex")*2);
ob->set("con",me->query("str"));
	this_object()->set("party",ps[k]["party"]);
	this_object()->set_skills(ps[k]["skills"]);
	this_object()->set_skill_map(ps[k]["skill_map"]);
	this_object()->set_skill_prepare(ps[k]["skill_prepare"]);
        i=me->query_skill("force",1)*2/3;
        e=me->query_skill("force",1)*2/3;
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
//        ob->set_skill("shiren-jianfa", i); 
//        ob->set_skill("shiren-quanfa", i);         
//ob->map_skill("unarmed", "shiren-quanfa");
//ob->map_skill("parry", "shiren-quanfa");

}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
        this_object()->clear_condition();
	command("hehe");
}

void die()
{
	unconcious();
}

int ask_job()
{

        object ob = this_player();
        object me = this_object();
me->clear_condition();
                command("say ��������" + me->query("qi") + "���������� " + me->query("eff_qi") + "��");
//                command("nod" + me->query("id"));
                command("say ��������" + me->query("jing") + "���������� " + me->query("eff_jing") + "��");
                return 1;
}
int ask_job2()
{
int maxpot;
        object ob = this_object();
        object me = this_player();
if (me->is_busy())
return 0;
maxpot=me->query_temp("maxpot")+10;
    command("say �ο�" + me->query("name") + "�书!");
ob->do_copy(me,maxpot,2);
ob->clear_condition();
me->start_busy(12);
return 1;
}