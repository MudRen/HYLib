// ITEM: /d/jingzhou/obj/jianpu.c
// Date: 99/05/31 by Byt


inherit ITEM;

void create()
{
        set_name("���ǽ���", ({ "liancheng jianpu", "jianpu" }));
        set_weight(600); 
        set("unique", 1); 
	if( clonep() )
		set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������Ļ�ֽ�飬��ҳ�����ϽǱ�˺ȥ��СС��һ�ǡ�\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "liancheng-jian",
                        "exp_required": 0,
                        "jing_cost":    30,
                        "difficulty":   20,
                 	"max_skill": 31,
                ]) );                
	     }
 
}

