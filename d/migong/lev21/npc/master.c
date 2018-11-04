// master.c

inherit NPC;

#include <ansi.h>
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
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIB"", ""HIB"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void create()
{
	mapping npc;
	string sex;
	npc=data[random(sizeof(data))];
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);

if (sex)
set("gender", "Ů��" );
else set("gender", "����" );
	set("combat_exp",3000000);

        set("nickname", HIB"����֮ħ��ʦ"NOR);
set("pubmaster",1);
        set("age", 34);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
        set("agi",25);
      set("dex",300);
      set("con",300);
     set("str" ,300);
       
    set("age", 20);
set("vendetta/authority",1);
	set("attitude","friendly");
set("pubmaster",1);
        set("max_neili", 925000);
        set("neili", 925000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
    (: perform_action, "spells.fireball" :),
    (: perform_action, "spells.firebolt" :),
    (: perform_action, "spells.meteor" :),
    (: perform_action, "spells.immolation" :),
        }) );
        set("long",
RED"
����֮ħ��ʦ, ������ڰ���ϵ��ħ��������
\n"NOR
	);
        set("combat_exp", 50000000);
        set("score", 200000);

        set_skill("parry", 220);
        set_skill("dodge", 220);
        set_skill("force", 200);
        set_skill("literate", 200);
	set_skill("sword", 200);
	set_skill("unarmed",280);
      set_skill("spells", 550+random(301));
      set_skill("magic-dark", 500+random(1500));
      set_skill("unarmed", 500);
      map_skill("spells", "magic-dark");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.zeroring" :),                                                            
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
        set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
        carry_object(__DIR__"obj/clothm")->wear();

}
int accept_object(object who, object ob)
{
	int i;
        if( !who->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ѧϰ����ܣ�\n");
	if (!(int)who->query_temp("learn_timem"))      
		who->set_temp("learn_timem", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("magic-ice",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("magic-ice",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("magic-ice",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 200;
		}
	}
	who->add_temp("learn_timem",i);
command("say ѧϰħ����Ҫ�����ĺ�ʱ�䣬��������ѧ�ɡ�");
	return 1;
}

int recognize_apprentice(object ob)
{
        if( !ob->query("zhuanbest",1))
        return 0;

	if( ob->query_temp("learn_timem") <= 0) return 0;
else         
ob->add_temp("learn_timem",-1);
return 1;
}
