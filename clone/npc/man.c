#include <ansi.h>
inherit NPC;
mapping *data=({
(["name":"����Ԫ��",	"id":"yuanlao",	"mw":-1,	]),
(["name":"���½̳���",	"id":"zhanglao",	"mw":1,	]),
(["name":"���ߵ�����",	"id":"daozhu",	"mw":-1,	"weapon":"blade",	]),
(["name":"ؤ�ﳤ��",	"id":"zhanglao",	"mw":1,	"weapon":"club",	]),
(["name":"��ɽ������",	"id":"yinzhe",	"mw":-1,	"weapon":"sword",	]),
(["name":"��ǰ������",	"id":"zhang",		"mw":1,	"weapon":"sword",	]),
(["name":"������ʦ",	"id":"chanshi",	"mw":1,	"weapon":"blade",]),
(["name":"���չ�����",	"id":"zhanglao",	"mw":-1,	"weapon":"whip",	]),
(["name":"ɽ����",		"id":"daiwang",	"mw":-1,	"weapon":"throwing",]),
(["name":"������ϴ�",	"id":"laoda",		"mw":-1,	"weapon":"hammer",	]),
(["name":"����ɽ����",	"id":"zhangmen",	"mw":1,	"weapon":"sword",]),
(["name":"���̰���",	"id":"bang",		"mw":1,	]),
(["name":"����а��ͽ",	"id":"tu",		"mw":-1,	]),
(["name":"��ػ����",	"id":"bang",		"mw":1,	"weapon":"blade",	]),
(["name":"ؤ�����",	"id":"dizi",		"mw":1,	"weapon":"club",	]),
(["name":"���޵���",	"id":"dizi",		"mw":-1,	"weapon":"blade",	]),
(["name":"��ǰ����",	"id":"shiwei",	"mw":1,	"weapon":"sword",	]),
(["name":"�䵱����ͽ",	"id":"dizi",		"mw":-1,	"weapon":"sword",]),
(["name":"��ɽ����ͽ",	"id":"dizi",		"mw":-1,	"weapon":"sword",	]),
(["name":"���չ�ʹ��",	"id":"shizhe",	"mw":-1,	"weapon":"whip",]),
(["name":"���ߵ�ʹ��",	"id":"shizhe",	"mw":-1,	"weapon":"blade",	]),
(["name":"���̽���ʹ",	"id":"shi",		"mw":1,	"weapon":"hammer",]),
(["name":"�ض���",	"id":"han",		"mw":1,	]),
(["name":"����ǿ��",	"id":"ren",	"mw":-1,	]),
(["name":"Ѳ��ͷ��",	"id":"touling",	"mw":1,	"weapon":"blade",	]),
(["name":"����ǿ��",	"id":"qiangdao",	"mw":-1,	"weapon":"blade",	]),
(["name":"����ɮ",		"id":"seng",		"mw":1,	"weapon":"club",	]),
(["name":"��ͷ��",		"id":"toutuo",	"mw":-1,	"weapon":"blade",	]),
(["name":"������",		"id":"wei",		"mw":-1,	"weapon":"sword",	]),
(["name":"��������",	"id":"shiwei",	"mw":-1,	"weapon":"whip",]),
(["name":"���ε�ʿ",	"id":"daoshi",	"mw":1,	"weapon":"sword",	]),
(["name":"����",		"id":"dao",		"mw":-1,	"weapon":"sword",]),
(["name":"�������",	"id":"guan",		"mw":1,	"weapon":"blade",	]),
(["name":"ɽ��ͷ",		"id":"dou",		"mw":-1,	"weapon":"hammer",]),
(["name":"������",	"id":"han",		"mw":1,	]),
(["name":"����",	"id":"biesan",	"mw":-1,	]),
(["name":"��ͷ",	"id":"bu tou",	"mw":1,	"weapon":"blade",	]),
(["name":"ǿ��",	"id":"ren",		"mw":-1,	"weapon":"blade",	]),
(["name":"����ɮ��","id":"seng",		"mw":1,	"weapon":"club",	]),
(["name":"���ֶ�ɮ","id":"seng",		"mw":-1,	"weapon":"club",	]),
(["name":"��ʿ",	"id":"wushi",		"mw":1,	"weapon":"sword",	]),
(["name":"ǿ��ͷ",	"id":"qiang dao",	"mw":-1,	"weapon":"hammer",]),
(["name":"����ɮ",	"id":"seng",		"mw":1,	"weapon":"blade",	]),
(["name":"��ɮ",	"id":"seng",		"mw":-1,	"weapon":"sword",]),
(["name":"��������","id":"shiwei",	"mw":1,	"weapon":"blade",	]),
(["name":"ɽ��",	"id":"sanzei",	"mw":-1,	"weapon":"throwing",]),
(["name":"׳��",	"id":"han",		"mw":1,	]),
(["name":"����å",	"id":"liumang",	"mw":-1,	]),
(["name":"����",	"id":"bu kuai",	"mw":1,	"weapon":"blade",	]),
(["name":"������",	"id":"fan",		"mw":-1,	"weapon":"blade",	]),
(["name":"��ɮ",	"id":"seng",		"mw":1,	"weapon":"club",	]),
(["name":"��ͷ��",	"id":"toutuo",	"mw":-1,	"weapon":"blade",	]),
(["name":"����",	"id":"xiake",		"mw":1,	"weapon":"sword",	]),
(["name":"ǿ��",	"id":"qiang dao",	"mw":-1,	"weapon":"throwing",]),
(["name":"׳ʿ",	"id":"shi",		"mw":1,	]),
(["name":"��",	"id":"ehan",		"mw":-1,	]),
(["name":"׳��",	"id":"ding",		"mw":1,	]),
(["name":"�׺�",	"id":"han",		"mw":-1,	]),
(["name":"����",	"id":"xing ren",	"mw":1,	]),
(["name":"����",	"id":"shang ren",	"mw":-1,	]),
(["name":"�ÿ�",	"id":"lv ke",		"mw":1,	]),
(["name":"����",	"id":"men ren",	"mw":1,	]),
(["name":"ѧͽ",	"id":"xue tu",	"mw":1,	]),
(["name":"������",	"id":"wu lai",	"mw":-1,	]),
(["name":"����",	"id":"lang ren",	"mw":-1,	]),
(["name":"����",	"id":"xing she",	"mw":1,	]),
(["name":"����ͽ",	"id":"tu",		"mw":-1,	]),
(["name":"����",	"id":"ke shang",	"mw":-1,	]),
(["name":"С��",	"id":"xiao shi",	"mw":1,	]),
(["name":"��ɫ��",	"id":"se gui",	"mw":-1,	]),
(["name":"����",	"id":"qing nian",	"mw":1,	]),
(["name":"������",	"id":"nian qing",	"mw":1,	]),
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

        set("dex",200);

	set_skill("sword",120);
	set_skill("club",120);
	set_skill("whip",120);
	set_skill("throwing",120);
	set_skill("parry",120);

set("per",16+random(20));
	set_skill("dodge",300);
	set("shen_type",npc["mw"]);
if (npc["mw"]=1) set("gender", "Ů��");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :),
        }) );
	set("max_neili",500+random(8550));
	set("max_jing",500+random(8550));
		set("max_qi",500+random(8550));
	set_skill("unarmed",230);
	set_skill("parry",230);
	set_skill("dodge",230);
	set("age",20+random(30));
	set("combat_exp",55000+random(8555000));
	set_temp("apply/attack",120);
	set_temp("apply/defense",20);
	set_temp("apply/armor",120);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
           (: random_move :),
           (: random_move :),
           (: random_move :),
        }) );

        set_temp("apply/attack", 30+random(380));
        set_temp("apply/defense",30+random(380));
        set_temp("apply/armor", 30+random(380));
        set_temp("apply/damage", 30+random(380));
        setup();
        set("check_time", time());
	if( weapon)
		carry_object(__DIR__"weapon/"+weapon)->wield();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",50+random(50));
}
       
