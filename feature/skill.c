// skill.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;
mapping wprepare;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }

void set_skill(string skill, int val)
{
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) ) skills = ([ skill: val ]);
	else skills[skill] = val;
}

int delete_skill(string skill)
{
	if( mapp(skills) ) {
		map_delete(skills, skill);
		if( mapp(learned) ) {
			map_delete(learned, skill);
			return undefinedp(learned[skill]);
		}
		return undefinedp(skills[skill]);
	}
	return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_map) ) {
		map_delete(skill_map, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

// This function 'prepare' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the prepared skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_prepare) ) {
		map_delete(skill_prepare, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_prepare) ) skill_prepare = ([ skill: mapped_to ]);
	else skill_prepare[skill] = mapped_to;
}

varargs void prepare_wskill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(wprepare) ) {
		map_delete(wprepare, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(wprepare) ) wprepare = ([ skill: mapped_to ]);
	else wprepare[skill] = mapped_to;
}


string query_skill_mapped(string skill)
{
	if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
		return skill_map[skill];
	return 0;
}

string query_skill_prepared(string skill)
{
	if( mapp(skill_prepare) && !undefinedp(skill_prepare[skill]) )
		return skill_prepare[skill];
	return 0;
}

string query_wprepared(string skill)
{
	if( mapp(wprepare) && !undefinedp(wprepare[skill]) )
		return wprepare[skill];
	return 0;
}

varargs int query_skill(string skill, int raw)
{
	if( !raw ) {
		int s;
		
		s = query_temp("apply/" + skill);
		if( mapp(skills) ) {
			s += skills[skill] / 2;
			if( mapp(skill_map) )
				s += skills[skill_map[skill]];
		}
		return s;
	}
	if( mapp(skills) && !undefinedp(skills[skill]) ) return skills[skill];
	return 0;
}

mapping query_skill_map()
{
	return skill_map;
}

mapping query_skill_prepare()
{
	return skill_prepare;
}

mapping query_wprepare()
{
       return wprepare;  
}


int skill_death_penalty()
{
	string *sk;
	int i;

	if( !mapp(skills) ) return 0;

	sk = keys(skills);
	if( !mapp(learned) )
		for(i = 0; i<sizeof(sk); i++) {
				skills[sk[i]]--;
			if( skills[sk[i]]<=0 ) 
{
			map_delete(skills, sk[i]);
		this_object()->map_skill("unarmed");
		this_object()->map_skill("hammer");
		this_object()->map_skill("blade");
		this_object()->map_skill("sword");
		this_object()->map_skill("staff");
		this_object()->map_skill("club");
		this_object()->map_skill("throwing");
		this_object()->map_skill("parry");
		this_object()->map_skill("dodge");
		this_object()->map_skill("magic");
		this_object()->map_skill("spells");
		this_object()->map_skill("leg");
		this_object()->map_skill("axe");
		this_object()->map_skill("array");
		this_object()->map_skill("whip");	
		this_object()->map_skill("finger");
		this_object()->map_skill("hand");	
		this_object()->map_skill("cuff");	
		this_object()->map_skill("claw");	
		this_object()->map_skill("strike");	
		this_object()->map_skill("force");	
		
		this_object()->prepare_skill("unarmed");
		this_object()->prepare_skill("hammer");
		this_object()->prepare_skill("blade");
		this_object()->prepare_skill("sword");
		this_object()->prepare_skill("staff");
		this_object()->prepare_skill("club");
		this_object()->prepare_skill("throwing");
		this_object()->prepare_skill("parry");
		this_object()->prepare_skill("dodge");
		this_object()->prepare_skill("magic");
		this_object()->prepare_skill("spells");
		this_object()->prepare_skill("leg");
		this_object()->prepare_skill("axe");
		this_object()->prepare_skill("array");
		this_object()->prepare_skill("whip");	
		this_object()->prepare_skill("finger");
		this_object()->prepare_skill("hand");	
		this_object()->prepare_skill("cuff");	
		this_object()->prepare_skill("claw");	
		this_object()->prepare_skill("strike");	
                this_object()->reset_action();
tell_object(this_object(),HIR "�����书Ϊ�㼶�ˣ�������enable ���е��书���ر���force��\n" NOR);
}
		}
	else
		for(i = 0; i<sizeof(sk); i++) {
			if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
				map_delete(learned, sk[i]);
			else {
				skills[sk[i]]--;
				if( skills[sk[i]]<=0 )
{
				map_delete(skills, sk[i]);
		this_object()->map_skill("unarmed");
		this_object()->map_skill("hammer");
		this_object()->map_skill("blade");
		this_object()->map_skill("sword");
		this_object()->map_skill("staff");
		this_object()->map_skill("club");
		this_object()->map_skill("throwing");
		this_object()->map_skill("parry");
		this_object()->map_skill("dodge");
		this_object()->map_skill("magic");
		this_object()->map_skill("spells");
		this_object()->map_skill("leg");
		this_object()->map_skill("axe");
		this_object()->map_skill("array");
		this_object()->map_skill("whip");	
		this_object()->map_skill("finger");
		this_object()->map_skill("hand");	
		this_object()->map_skill("cuff");	
		this_object()->map_skill("claw");	
		this_object()->map_skill("strike");	
		this_object()->map_skill("force");	
		
		this_object()->prepare_skill("unarmed");
		this_object()->prepare_skill("hammer");
		this_object()->prepare_skill("blade");
		this_object()->prepare_skill("sword");
		this_object()->prepare_skill("staff");
		this_object()->prepare_skill("club");
		this_object()->prepare_skill("throwing");
		this_object()->prepare_skill("parry");
		this_object()->prepare_skill("dodge");
		this_object()->prepare_skill("magic");
		this_object()->prepare_skill("spells");
		this_object()->prepare_skill("leg");
		this_object()->prepare_skill("axe");
		this_object()->prepare_skill("array");
		this_object()->prepare_skill("whip");	
		this_object()->prepare_skill("finger");
		this_object()->prepare_skill("hand");	
		this_object()->prepare_skill("cuff");	
		this_object()->prepare_skill("claw");	
		this_object()->prepare_skill("strike");	
                this_object()->reset_action();
tell_object(this_object(),HIR "�����书Ϊ�㼶�ˣ�������enable ���е��书���ر���force��\n" NOR);
}
			}
		}
//	if (mapp(skill_map)) map_delete(skill_map, "force");
	return 1;
}


varargs void improve_skill(string skill, int amount, int weak_mode)
{
	int spi = 40;
	int lvl = 0;
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !weak_mode || !userp(this_object()) ) {
		if( !mapp(skills) ) skills = ([]);
//		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

    if (!weak_mode && mapp(skills) && SKILL_D(skill)->type() == "martial") {
		lvl = skills[skill];
		if (lvl*lvl*lvl/10 > this_object()->query("combat_exp")) {
			weak_mode = 1;
			if (!random(3)) tell_object(this_object(),
				HIY "����ʵս���鲻�㣬�谭����ġ�" + to_chinese(skill) + "��������\n" NOR);
		}
	}
	if( !weak_mode ) {
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	// Give learning penalty to those learning too much skills.
	spi = 40;
	if( sizeof(skills) > spi )
		amount /= sizeof(skills) - spi;

	if( amount <= 0 ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;
//	put a upper limit here so that we can implment research_skill
	if(learned[skill] > (skills[skill] + 1) * (skills[skill] + 1))
	learned[skill] = (skills[skill] + 1) * (skills[skill] + 1) +1;
	if( (!weak_mode || !userp(this_object()))
	&&	learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
		skills[skill]= skills[skill]+1;

		learned[skill] = 0;
		tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
		SKILL_D(skill)->skill_improved(this_object());
	}
}

varargs int query_skillo(string skill, int raw)
{
        if (! raw)
        {
                int s;
                
                s = query_temp("apply/" + skill);
                if (mapp(skills))
                {
                        s += skills[skill] / 2;
                        if (mapp(skill_map))
                                s += skills[skill_map[skill]];
                }
                return s;
        }
        if (mapp(skills) && ! undefinedp(skills[skill]))
        {
                int a;

                a = skills[skill];
                return a;
        }
        return 0;
}

int skill_expell_penalty()
{
        int i;
        string *skname;

        if (! mapp(skills)) 
        return 1;

        skname = keys(skills);
        for (i = 0; i < sizeof(skname); i++)
        {
                if (file_size(SKILL_D(skname[i]) + ".c") < 0)
                {
                        delete_skill(skname[i]);
                        continue;
                }

                // �Դ����书������
                if (SKILL_D(skname[i])->is_invent_skill()) 
                        continue;

                if (SKILL_D(skname[i])->type() != "martial" ||
                    skname[i] == "martial-cognize")
                        continue;

                if (SKILL_D(skname[i])->valid_enable("parry") ||
                    SKILL_D(skname[i])->valid_enable("dodge") ||
                    SKILL_D(skname[i])->valid_enable("throwing") ||
                    SKILL_D(skname[i])->valid_enable("force"))
                {
                        delete_skill(skname[i]);
                        continue;
                }

                if (query_skillo(skname[i], 1) >= 100)
                        set_skill(skname[i], 100);
        }

        skill_map = 0;
        skill_prepare = 0;
}
void set_skills(mapping mp) { skills = mp; }
void set_learned(mapping mp) { learned = mp; }
void set_skill_map(mapping mp) { skill_map = mp; }
void set_skill_prepare(mapping mp) { skill_prepare = mp; }
