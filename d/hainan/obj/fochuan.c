inherit ITEM;

void create()
{
  set_name("̴ľ��", ({ "fo chuan", "chuan" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
    set("long", "һ�ٵ��˿�̴ľ���Ӵ��ɵķ�,����΢����һЩ����
��ϸ��ȥ,���Ĵ���Ϊ:��ɮ��,һ��ɱ������,����������,����Ӧ��������,
Ψ����ƽ����ѧ,���̾ʹ�ʧ��.���ڷ�,��֮��Ե. 
......  ......
��\n");
        set("material", "wood");
        set("skill", ([
                        "name": "blade",
                        "exp_required": 300,
			"sen_cost":20+random(11),
			"max_skill":200,
]) );
        }
}

