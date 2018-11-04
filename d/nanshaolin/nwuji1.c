// Last Modified by winder on May. 29 2001
// nwuji1.c

inherit ITEM;

string* titles = ({
	"�黨ָ",
	"һָ��",
	"ӥצ��",
	"��צ��",
	"������",
	"����ǧҶ��",
	"������",
	"ɢ����",
	"�޺�ȭ",
});

string* skills = ({
	"nianhua-zhi",
	"yizhi-chan",
	"yingzhua-gong",
	"longzhua-gong",
	"fengyun-shou",
	"qianye-shou",
	"banruo-zhang",
	"sanhua-zhang",
	"luohan-quan",
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "shaolin wuji", "wuji" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
	set("value", 500);
	set("material", "paper");
	set("skill", ([
		"name":	skills[i],
		"exp_required":	10000,
		"jing_cost": 15+random(30),
		"difficulty":	25,
		"max_skill":	99
	]) );
}
