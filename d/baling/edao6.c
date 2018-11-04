// baling/edao1
// Room in 巴陵
inherit ROOM;

void create()
{
	set("short", "金刀峡");
	set("long", @LONG
金刀峡地势雄伟,以峡著险，以林见秀，以岩称奇，以水显幽。
金刀峡长约10公里，分上下两段。上段由于喀斯特地质作用，地面
切割强烈，金刀神功般形成了独特的峡谷幽壑，石壁如削，两山岈
合，垂直高度超过百米，上有古藤倒挂，下有潺潺流水；下段由于
流水侵蚀的作用，有洞穴群提高潭潭相连，飞泉瀑布层层叠叠，古
钟乳、石笋、石柱更是千姿百态，让人惊叹不已。凭栈探幽，可感
悟那蕴藏于大自然山水的天地灵气。十公里风景线以雄、险、奇、
幽著称，集瀑、泉、洞、峡于一体。有惊魂台、藏刀洞、悬天飞瀑
、天犬洞、神鹰峡、狮头峡、一线天、沙溪湖、中峡天然浴场、千
幻古岩、弥乐佛、心形潭等四十多个景点可供游客探险 被游客誉
为“梦中的香格里拉”、“中国第一险峡” 

LONG
	);

	set("exits", ([
		"southwest" : __DIR__"edao7",
                "north" : __DIR__"nanmen",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


