 // movebook.c
inherit ITEM; 
void create()
{
        set_name("����", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
                        "�ᵽһЩ��Ծ����ʲ��ġ�\n");
                set("value", 70);
                set("material", "paper");
                set("skill", ([
                        "name":                 "move", 
                        "exp_required": 0,                              
                        "sen_cost":             20,                             
                        "difficulty":   20,             
                        "max_skill":    30              
                ]) );
        }
        
}   
